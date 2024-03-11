import torch
import torch.nn as nn
from torch.nn import functional as F
from torch.nn.parameter import Parameter
from matplotlib import pyplot as plt
import copy

def show_heatmaps(matrices, xlabel, ylabel, titles=None, figsize=(2.5, 2.5), cmap='Reds'):
    '''显示矩阵热图'''
    num_rows, num_cols = matrices.shape[0], matrices.shape[1]
    fig, axes = plt.subplots(num_rows, num_cols, figsize=figsize, sharex=True, sharey=True, squeeze=False)
    for i, (row_axes, row_matrices) in enumerate(zip(axes, matrices)):
        for j, (ax, matrix) in enumerate(zip(row_axes, row_matrices)):
            pcm = ax.imshow(matrix.detach().numpy(), cmap=cmap)
            if i == num_rows - 1:
                ax.set_xlabel(xlabel)
            if j == 0:
                ax.set_ylabel(ylabel)
            if titles:
                ax.set_title(titles[j])
    fig.colorbar(pcm, ax=axes, shrink=0.6)
    plt.show()


class Multi_Head_Self_Attention(nn.Module):
    def __init__(self, embed_dim, num_heads, dropout=0., bias=True):
        super(Multi_Head_Self_Attention, self).__init__()
        """
        param embed_dim: 词嵌入的维度, 即d_model,论文中的默认值为512
        param num_heads: 多头注意力中多头的数量, 也就是前面的n_head参数, 论文中的默认值为8
        param bias: 最后对多头的注意力(组合)输出进行线性变换时, 是否使用偏置
        """
        self.embed_dim = embed_dim # d_model
        self.head_dim = embed_dim // num_heads # d_k, d_v
        self.kdim = self.head_dim
        self.vdim = self.head_dim
        self.num_heads = num_heads # 多头个数
        self.dropout = dropout
        assert self.head_dim * self.num_heads == self.embed_dim
        # 限制d_k = d_v = d_model // num_head
        self.q_proj_weight = Parameter(torch.Tensor(embed_dim, embed_dim))
        # embed_dim = kdim * num_heads
        # 同时初始化num_heads个W_q堆叠而成, 即num_heads个头
        self.k_proj_weight = Parameter(torch.Tensor(embed_dim, embed_dim))
        # W_k, embed_dim = k_dim * num_heads
        self.v_proj_weight = Parameter(torch.Tensor(embed_dim, embed_dim))
        # W_v, embed_dim = v_dim * num_heads
        self.out_proj = nn.Linear(embed_dim, embed_dim, bias=bias)
        # 最后将所有的z组合起来的时候, 也是一次性完成, embed_dim = v_dim * num_heads
    
    def forward(self, query, key, value, attn_mask=None, key_padding_mask=None):
        '''
        论文中, 编码时query, key, value都是同一个输入
        解码时, 输入的部分也是同一个输入
        解码和编码交互时key, value指的是memory, query指的是tgt
        param query: [tgt_len, batch_size, embed_dim], tgt_len 表示目标序列的长度
        param key: [src_len, batch_size, embed_dim], src_len 表示源序列的长度
        param value: [src_len, batch_size, embed_dim], src_len 表示源序列的长度
        param attn_mask:[tgt_len,src_len] or [num_heads*batch_size,tgt_len, src_len]
        一般只在解码时使用，为了并行一次喂入所有解码部分的输入, 所以要用 mask 来进行掩盖当前时刻之后的位置信息
        param key_padding_mask: [batch_size, src_len], src_len 表示源序列的长度
        
        return:
        attn_output: [tgt_len, batch_size, embed_dim]
        attn_output_weights: # [batch_size, tgt_len, src_len]
        '''
        return multi_head_attention_forward(query, key, value, self.num_heads, self.dropout, self.out_proj.weight, self.out_proj.bias,
                                            training=self.training, key_padding_mask=key_padding_mask, q_proj_weight=self.q_proj_weight,
                                            k_proj_weight=self.k_proj_weight, v_proj_weight=self.v_proj_weight, attn_mask=attn_mask)


def multi_head_attention_forward(
        query, # [tgt_len, batch_size, embed_dim]
        key, # [src_len, batch_size, embed_dim]
        value, # [src_len, batch_size, embed_dim]
        num_heads,
        dropout_p,
        out_proj_weight,
        out_proj_bias,
        training=True,
        key_padding_mask=None, # [batch_size,src_len/tgt_len]
        q_proj_weight=None, # [embed_dim, kdim * nums_heads]
        k_proj_weight=None, # [embed_dim, kdim * nums_heads]
        v_proj_weight=None, # [embed_dim, kdim * nums_heads]
        attn_mask=None # [tgt_len, src_len]
        ):
    # 第一阶段: 计算Q, K, V
    q = F.linear(query, q_proj_weight)
    # [tgt_len, batch_size, embed_dim] x [embed_dim, kdim * num_heads]
    # = [tgt_len, batch_size, kdim * num_heads]
    k = F.linear(key, k_proj_weight)
    # [src_len, batch_size, embed_dim] x [embed_dim, kdim * num_heads]
    # = [src_len, batch_size, kdim * num_heads]
    v = F.linear(value, v_proj_weight)
    # [src_len, batch_size, embed_dim] x [embed_dim, kdim * num_heads]
    # = [src_len, batch_size, kdim * num_heads]
    # 第二阶段: 缩放, 以及attn_mask维度判断
    tgt_len, bsz, embed_dim = query.size() # [tgt_len,batch_size,embed_dim]
    src_len = key.size(0)
    head_dim = embed_dim // num_heads # num_heads * head_dim = embed_dim
    scaling = float(head_dim) ** -0.5
    q = q * scaling # [query_len, batch_size, kdim * num_heads]

    if attn_mask is not None:
        # [tgt_len, src_len] or [num_heads * batch_size, tgt_len, src_len]
        if attn_mask.dim == 2:
            attn_mask = attn_mask.unsqueeze(0) # [1, tgt_len, src_len]扩充维度
            if list(attn_mask.size()) != [1, query.size(0), key.size(0)]:
                raise RuntimeError('The size of the 2D attn_mask is not correct.')
        elif attn_mask.dim == 3:
            if list(attn_mask.size()) != [num_heads * bsz, query.size(0), key.size(0)]:
                raise RuntimeError('The size of the 3D attn_mask is not correct.')
    
    # attn_mask维度强转为3D
    # 第三部分: 计算得到注意力权重矩阵
    q = q.contiguous().view(tgt_len, bsz * num_heads, head_dim).transpose(0, 1)
    # [batch_size * num_heads, tgt_len, kdim]
    # 因为前面是num_heads个头一起参与的计算, 所以这里要进行一下变形, 以便于后面计算。且同时交换了0, 1两个维度
    k = k.contiguous().view(src_len, bsz * num_heads, head_dim).transpose(0, 1)
    # [batch_size * num_heads, src_len, vkdim]
    v = v.contiguous().view(-1, bsz * num_heads, head_dim).transpose(0, 1)
    # [batch_size * num_heads, src_len, vdim]
    attn_output_weights = torch.bmm(q, k.transpose(1, 2))
    # [batch_size * num_heads, tgt_len, kdim] x [batch_size * num_heads, kdim, src_len]
    # = [batch_size * num_heads, tgt_len, src_len] 这就num_heads个QK^T相乘后的注意力矩阵
    # 第四部分: 进行相关掩码操作
    if attn_mask is not None:
        attn_output_weights += attn_mask
        # [batch_size * num_heads, tgt_len, src_len]
    if key_padding_mask is not None:
        attn_output_weights = attn_output_weights.view(bsz, num_heads, tgt_len, src_len)
        # 变成[batch_size, num_heads, tgt_len, src_len]的形状
        attn_output_weights = attn_output_weights.masked_fill(key_padding_mask.unsqueeze(1).unsqueeze(2), float('-inf'))
        # 扩展维度, 从[batch_size, src_len]变成[batch_size, 1, 1, src_len]
        attn_output_weights = attn_output_weights.view(bsz * num_heads, tgt_len, src_len)
        # [batch_size * num_heads, tgt_len, src_len]
    attn_output_weights = F.softmax(attn_output_weights, dim=-1)
    attn_output_weights = F.dropout(attn_output_weights, p=dropout_p, training=training)
    attn_output = torch.bmm(attn_output_weights, v)
    # Z = [batch_size * num_heads, tgt_len, src_len] x [batch_size * num_heads , src_len, vdim]
    # = [batch_size * num_heads, tgt_len, vdim]
    # 这就num_heads个 Attention(Q,K,V)结果
    attn_output = attn_output.transpose(0, 1).contiguous().view(tgt_len, bsz, num_heads * head_dim)
    # 先transpose成 [tgt_len, batch_size * num_heads, kdim]
    # 再view成[tgt_len, batch_size, num_heads * kdim]
    attn_output_weights = attn_output_weights.view(bsz, num_heads, tgt_len, src_len)
    # [batch_size * num_heads, tgt_len, src_len] -> [batch_size, num_heads, tgt_len, src_len]
    Z = F.linear(attn_output, out_proj_weight, out_proj_bias)
    return Z, attn_output_weights.sum(dim=1) / num_heads
    # 将num_heads个注意力权重矩阵按对应维度取平均


def _get_clones(module, N):
    return nn.ModuleList([copy.deepcopy(module) for _ in range(N)])


class MyTransformerEncoderLayer(nn.Module):
    def __init__(self, d_model, nhead, dim_feedforward=2048, dropout=0.1):
        super(MyTransformerEncoderLayer, self).__init__()
        '''
        param d_model: d_k = d_v = d_model / nhead = 64,模型中向量的维度, 默认值为512
        param nhead: 多头注意力机制中多头的数量, 论文默认为值8
        param dim_feedforward: 全连接中向量的维度, 论文默认值为2048
        param dropout: 丢弃率, 论文中的默认值为0.1 
        '''
        self.self_attn = Multi_Head_Self_Attention(d_model, nhead, dropout)
        self.dropout1 = nn.Dropout(dropout)
        self.norm1 = nn.LayerNorm(d_model)

        self.linear1 = nn.Linear(d_model, dim_feedforward)
        self.dropout = nn.Dropout(dropout)
        self.linear2 = nn.Linear(dim_feedforward, d_model)
        self.activation = F.relu
        self.dropout2 = nn.Dropout(dropout)
        self.norm2 = nn.LayerNorm(d_model)
    
    def forward(self, src, src_mask=None, src_key_padding_mask=None):
        '''
        param src: 编码部分的输入, 形状为[src_len, batch_size, embed_dim]
        param src_mask: 编码部分输入的padding情况, 形状为[batch_size, src_len]
        return: [src_len, batch_size, num_heads * kdim] <=> [src_len, batch_size, embed_dim]
        '''
        src2 = self.self_attn(src, src, src, attn_mask=src_mask, key_padding_mask=src_key_padding_mask)[0]
        # 计算多头注意力
        # src2: [src_len, batch_size, num_heads * kdim] num_heads * kdim = embed_dim
        src = src + self.dropout1(src2) # 残差连接
        src = self.norm1(src) # [src_len, batch_size, num_heads * kdim]

        src2 = self.activation(self.linear1(src))
        # [src_len, batch_size, dim_feedforward]
        src2 = self.linear2(self.dropout2(src2))
        # [src_len, batch_size, num_heads * kdim]
        src = src + self.dropout2(src2) # 残差连接
        src = self.norm2(src) # [src_len, batch_size, num_heads * kdim]
        return src # [src_len, batch_size, num_heads * kdim] <=> [src_len, batch_size, embed_dim]


class MyTransformerEncoder(nn.Module):
    def __init__(self, encoder_layer, num_layers, norm=None):
        super(MyTransformerEncoder, self).__init__()
        '''
        encoder_layer: 就是包含有多头注意力机制的一个编码层
        num_layers: 克隆得到多个encoder_layers 论文中默认为6
        norm: 归一化层
        '''
        self.layers = _get_clones(encoder_layer, num_layers)
        self.num_layers = num_layers
        self.norm = norm
    
    def forward(self, src, mask=None, src_key_padding_mask=None):
        '''
        param src: 编码部分的输入, 形状为[src_len, batch_size, embed_dim]
        param mask: 编码部分输入的padding情况, 形状为[batch_size, src_len]
        return:# [src_len, batch_size, num_heads * kdim] <=> [src_len, batch_size, embed_dim]
        '''
        output = src
        for mod in self.layers:
            output = mod(output, src_mask=mask, src_key_padding_mask=src_key_padding_mask)
        # 多个encoder_layers层堆叠后的前向传播过程
        if self.norm is not None:
            output = self.norm(output)
        return output # [src_len, batch_size, num_heads * kdim] <=> [src_len, batch_size, embed_dim]


class MyTransformerDecoderLayer(nn.Module):
    def __init__(self, d_model, nhead, dim_feedforward=2048, dropout=0.1):
        super(MyTransformerDecoderLayer, self).__init__()
        self.self_attn = Multi_Head_Self_Attention(embed_dim=d_model, num_heads=nhead, dropout=dropout)
        # Masked Multi-Head Attention
        self.multihead_attn = Multi_Head_Self_Attention(embed_dim=d_model, num_heads=nhead, dropout=dropout)
        # Multi-Head Attention
        self.linear1 = nn.Linear(d_model, dim_feedforward)
        self.dropout = nn.Dropout(dropout)
        self.linear2 = nn.Linear(dim_feedforward, d_model)

        self.norm1 = nn.LayerNorm(d_model)
        self.norm2 = nn.LayerNorm(d_model)
        self.norm3 = nn.LayerNorm(d_model)
        self.dropout1 = nn.Dropout(dropout)
        self.dropout2 = nn.Dropout(dropout)
        self.dropout3 = nn.Dropout(dropout)
        self.activation = F.relu
    
    def forward(self, tgt, memory, tgt_mask=None, memory_mask=None, tgt_key_padding_mask=None, memory_key_padding_mask=None):
        tgt2 = self.self_attn(tgt, tgt, tgt, attn_mask=tgt_mask, key_padding_mask=tgt_key_padding_mask)[0]
        # 计算多头注意力
        # src2: [tgt_len, batch_size, num_heads * kdim] num_heads * kdim = embed_dim
        tgt = tgt + self.dropout1(tgt2) # 残差连接
        tgt = self.norm1(tgt) # [tgt_len, batch_size, num_heads * kdim]

        tgt2 = self.multihead_attn(tgt, memory, memory, attn_mask=memory_mask, key_padding_mask=memory_key_padding_mask)[0]
        # [tgt_len, batch_size, embed_dim]
        tgt = tgt + self.dropout2(tgt2)
        tgt = self.norm2(tgt2)

        tgt2 = self.activation(self.linear1(tgt))
        tgt2 = self.linear2(self.dropout(tgt2))
        tgt = tgt + self.dropout3(tgt2)
        tgt = self.norm3(tgt)
        return tgt


class MyTransformerDecoder(nn.Module):
    def __init__(self, decoder_layer, num_layers, norm=None):
        super(MyTransformerDecoder, self).__init__()
        self.layers = _get_clones(decoder_layer, num_layers)
        self.num_layers = num_layers
        self.norm = norm
    
    def forward(self, tgt, memory, tgt_mask=None, memory_mask=None, tgt_key_padding_mask=None, memory_key_padding_mask=None):
        output = tgt
        for mod in self.layers:
            output = mod(output, memory, tgt_mask=tgt_mask, memory_mask=memory_mask, tgt_key_padding_mask=tgt_key_padding_mask, memory_key_padding_mask=memory_key_padding_mask)

        # 多个decoder_layers层堆叠后的前向传播过程
        if self.norm is not None:
            output = self.norm(output)
        return output # [tgt_len, batch_size, num_heads * kdim] <=> [tgt_len, batch_size, embed_dim]


class MyTransformer(nn.Module):
    def __init__(self, d_model=512, nhead=8, num_encoder_layers=6, num_decoder_layers=6, dim_feedforward=2048, dropout=0.1):
        super(MyTransformer, self).__init__()
        '''
        param d_model: d_k = d_v = d_model / nhead = 64, 模型中向量的维度, 默认值为512
        param nhead: 多头注意力机制中多头的数量, 论文默认为8
        param num_encoder_layers: encoder堆叠的数量, 论文中的N, 论文默认值为6
        param num_decoder_layers: decoder堆叠的数量, 论文中的N, 论文默认值为6
        param dim_feedforward: 全连接中向量的维度, 论文默认值为2048
        param dropout: 丢弃率, 论文中的默认值为0.1
        '''
        # ================ 编码部分 =====================
        encoder_layer = MyTransformerEncoderLayer(d_model, nhead, dim_feedforward, dropout)
        encoder_norm = nn.LayerNorm(d_model)
        self.encoder = MyTransformerEncoder(encoder_layer, num_encoder_layers, encoder_norm)
        # ================ 解码部分 =====================
        decoder_layer = MyTransformerDecoderLayer(d_model, nhead, dim_feedforward, dropout)
        decoder_norm = nn.LayerNorm(d_model)
        self.decoder = MyTransformerDecoder(decoder_layer, num_decoder_layers, decoder_norm)
        self._reset_parameters() # 初始化模型参数
        self.d_model = d_model
        self.nhead = nhead
    
    def forward(self, src, tgt, src_mask=None, tgt_mask=None, memory_mask=None, src_key_padding_mask=None, tgt_key_padding_mask=None, memory_key_padding_mask=None):
        '''
        param src: [src_len, batch_size, embed_dim]
        param tgt: [tgt_len, batch_size, embed_dim]
        param src_mask: None
        param tgt_mask: [tgt_len, tgt_len]
        param memory_mask: None
        param src_key_padding_mask: [batch_size, src_len]
        param tgt_key_padding_mask: [batch_size, tgt_len]
        param memory_key_padding_mask: [batch_size, src_len]
        return:[tgt_len, batch_size, num_heads * kdim]
        '''
        memory = self.encoder(src, mask=src_mask, src_key_padding_mask=src_key_padding_mask)
        # [src_len, batch_size, embed_dim(num_heads * kdim)]
        output = self.decoder(tgt=tgt, memory=memory, tgt_mask=tgt_mask, memory_mask=memory_mask, tgt_key_padding_mask=tgt_key_padding_mask, memory_key_padding_mask=memory_key_padding_mask)
        return output
        # [tgt_len, batch_size, embed_dim]
    
    def _reset_parameters(self):
        for p in self.parameters():
            if p.dim() > 1:
                nn.init.xavier_uniform_(p) # 使用Xavier初始化
    
    def generate_square_subsequent_mask(self, sz):
        mask = (torch.triu(torch.ones(sz, sz)) == 1).transpose(0, 1)
        mask = mask.float().masked_fill(mask==0, float('-inf')).masked_fill(mask==1, float(0.0))
        return mask # [sz, sz]


'''
if __name__ == "__main__":
    src_len = 5
    batch_size = 2
    dmodel = 32
    num_head = 1
    src = torch.rand((src_len, batch_size, dmodel)) # shape: [src_len, batch_size, embed_dim]
    src_key_padding_mask = torch.tensor([
        [True, True, True, False, False],
        [True, True, True, True, False]]) # shape: [batch_size, src_len]
    my_mh = Multi_Head_Self_Attention(embed_dim=dmodel, num_heads=num_head)
    result, atw = my_mh(src, src, src, key_padding_mask=src_key_padding_mask)
    print(result, atw)
    show_heatmaps(atw.unsqueeze(0), xlabel='Keys', ylabel='Queries')

if __name__ == "__main__":
    x = torch.tensor([[1, 3, 5, 7, 9],
                      [2, 4, 6, 8, 10]], dtype=torch.long)
    x = x.reshape(5, 2) # [src_len, batch_size]
    print(x)
    token_embedding = TokenEmbedding(vocab_size=11, emb_size=512)
    x = token_embedding(tokens=x)
    pos_embedding = PositionalEncoding(d_model=512)
    x = pos_embedding(x=x)
    print(x.shape) # torch.Size([5, 2, 512])
    print(x)
if __name__ == "__main__":
    src_len = 5
    batch_size = 2
    dmodel = 32
    num_head = 4
    num_layers = 2
    src = torch.rand((src_len, batch_size, dmodel)) # [src_len, batch_size, embed_dim]
    src_key_padding_mask = torch.tensor([[True, True, True, False, False],
                                         [True, True, True, True, False]]) # [batch_size, src_len]
    my_transformer_encoder_layer = MyTransformerEncoderLayer(d_model=dmodel, nhead=num_head)
    my_transformer_encoder = MyTransformerEncoder(encoder_layer=my_transformer_encoder_layer, num_layers=num_head, norm=nn.LayerNorm(dmodel))
    memory = my_transformer_encoder(src, mask=None, src_key_padding_mask=src_key_padding_mask)
    print(memory.shape) # torch.Size([5, 2, 32])
'''
if __name__ == "__main__":
    src_len = 5
    batch_size = 2
    dmodel = 32
    tgt_len = 6
    num_head = 8
    src = torch.rand((src_len, batch_size, dmodel)) # shape: [src_len, batch_size, embed_dim]

    src_key_padding_mask = torch.tensor([[True, True, True, False, False],
                                         [True, True, True, True, False]]) # shape: [batch_size, src_len]
    tgt = torch.rand((tgt_len, batch_size, dmodel)) # shape: [tgt_len, batch_size, embed_dim]
    tgt_key_padding_mask = torch.tensor([[True, True, True, False, False, False],
                                         [True, True, True, True, False, False]]) # shape: [batch_size, tgt_len]
    mytransformer = MyTransformer(d_model=dmodel, nhead=num_head, num_encoder_layers=6, num_decoder_layers=6, dim_feedforward=500)
    tgt_mask = mytransformer.generate_square_subsequent_mask(tgt_len)
    out = mytransformer(src=src, tgt=tgt, tgt_mask=tgt_mask, src_key_padding_mask=src_key_padding_mask, tgt_key_padding_mask=tgt_key_padding_mask, memory_key_padding_mask=src_key_padding_mask)
    print(out.shape)
