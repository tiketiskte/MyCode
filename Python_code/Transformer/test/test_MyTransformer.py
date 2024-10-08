import torch
from MyTransformer import MyTransformer
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