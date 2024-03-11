import torch
import torch.nn as nn
from math import sqrt
from matplotlib import pyplot as plt
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

class Attention(nn.Module):
    # input: batch_size * seq_len * input_dim
    # q: batch_size * n_q * d_q
    # k: batch_size * n_k * d_k
    # v: batch_size * n_v * d_v
    # in fact, n_q != n_k = n_v, d_q = d_k != d_v
    def __init__(self):
        super(Attention, self).__init__()

    def forward(self, q, k, v):
        # Q * K.T()
        # batch_size * seq_len * seq_len
        self.attention = nn.Softmax(dim=-1)(torch.bmm(q, k.permute(0, 2, 1)) * sqrt(q.size(1)))
        # Q * K.T() * V
        # batch_size * seq_len * dim_v
        output = torch.bmm(self.attention, v)
        return output


class Multi_Head_Attention(nn.Module):
    def __init__(self, hid_dim, n_heads):
        super(Multi_Head_Attention, self).__init__()
        assert hid_dim % n_heads == 0
        self.hid_dim = hid_dim
        self.n_heads = n_heads
        self.head_dim = hid_dim // n_heads

        self.fc_q = nn.Linear(hid_dim, hid_dim, bias=False)
        self.fc_k = nn.Linear(hid_dim, hid_dim, bias=False)
        self.fc_v = nn.Linear(hid_dim, hid_dim, bias=False)

        self.fc_o = nn.Linear(hid_dim, hid_dim, bias=False)

        self.scale = torch.sqrt(torch.FloatTensor([self.head_dim]))
    
    def forward(self, query, key, value):
        batch_size = query.size(0)
        # query = [batch_size, query_len, hid_dim]
        # key = [batch_size, key_len, hid_dim]
        # value = [batch_size, value_len, hid_dim]

        Q = self.fc_q(query)
        K = self.fc_k(key)
        V = self.fc_v(value)

        Q = Q.view(batch_size, -1, self.n_heads, self.head_dim).permute(0, 2, 1, 3) # Q = [batchsize, n_heads, query_len, head_dim]
        K = K.view(batch_size, -1, self.n_heads, self.head_dim).permute(0, 2, 1, 3) # K = [batchsize, n_heads, key_len, head_dim]
        V = V.view(batch_size, -1, self.n_heads, self.head_dim).permute(0, 2, 1, 3) # V = [batchsize, n_heads, value_len, head_dim]

        attention = nn.Softmax(dim=-1)(torch.matmul(Q, K.permute(0, 1, 3, 2)) / self.scale) # attention = [batch_size, n_heads, query_len, key_len]
        out_put = torch.matmul(attention, V) # output = [batch_size, n_heads, query_len, head_dim]
        out_put = out_put.permute(0, 2, 1, 3).contiguous() # output = [batch_size, query_len, n_heads, head_dim]
        out_put = out_put.view(batch_size, -1, self.hid_dim) # output = [batch_size, query_len, hid_dim]
        out_put = self.fc_o(out_put)
        return out_put, attention

seq_len, in_dim = 3, 4
d_qk, d_v = 4, 4
batch = 2
query = torch.randn(batch, seq_len, in_dim)
key = torch.randn(batch, seq_len, in_dim)
value = torch.randn(batch, seq_len, in_dim)
attention = Multi_Head_Attention(in_dim, n_heads=2)
attn, out_put = attention(query, key, value)

print(attn)
print(out_put)
show_heatmaps(attn.unsqueeze(0), xlabel='Keys', ylabel='Queries')