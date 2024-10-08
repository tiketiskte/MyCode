import torch
from math import sqrt
import torch.nn as nn


class SelfAttention(nn.Module):
    # input : batch_size * seq_len * input_dim
    # q : batch_size * input_dim * dim_k
    # k : batch_size * input_dim * dim_k
    # v : batch_size * input_dim * dim_v
    def __init__(self, input_dim, dim_k, dim_v):
        super(SelfAttention, self).__init__()
        self.q = nn.Linear(input_dim, dim_k)
        self.k = nn.Linear(input_dim, dim_k)
        self.v = nn.Linear(input_dim, dim_v)
        self._norm_fact = 1 / sqrt(dim_k)

    def forward(self, x):
        Q = self.q(x)  # Q: batch_size * seq_len * dim_k
        K = self.k(x)  # K: batch_size * seq_len * dim_k
        V = self.v(x)  # V: batch_size * seq_len * dim_v

        attn = nn.Softmax(dim=-1)((torch.bmm(Q, K.permute(0, 2, 1))) * self._norm_fact)
        # Q * K.T() # batch_size * seq_len * seq_len
        output = torch.bmm(attn, V)  # batch_size * seq_len * dim_v
        return output


X = torch.randn(4, 3, 2)
print(X)
self_attention = SelfAttention(2, 6, 5)
res = self_attention(X)
print(res)
print(res.shape)
