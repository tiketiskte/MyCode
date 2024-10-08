import torch
from math import sqrt
import torch.nn as nn

class Multi_Head_Attention(nn.Module):
    # input : batch_size * seq_len * input_dim
    # q : batch_size * input_dim * dim_k
    # k : batch_size * input_dim * dim_k
    # v : batch_size * input_dim * dim_v
    def __init__(self, input_dim, dim_k, dim_v, nums_head):
        super(Multi_Head_Attention, self).__init__()
        assert dim_k % nums_head == 0
        assert dim_v % nums_head == 0
        self.q = nn.Linear(input_dim, dim_k)
        self.k = nn.Linear(input_dim, dim_k)
        self.v = nn.Linear(input_dim, dim_v)

        self.nums_head = nums_head
        self.dim_k = dim_k
        self.dim_v = dim_v
        self._norm_fact = 1 / sqrt(dim_k)
    
    def forward(self, x):
        Q = self.q(x).reshape(x.shape[0], x.shape[1], self.nums_head, self.dim_k // self.nums_head)
        K = self.k(x).reshape(x.shape[0], x.shape[1], self.nums_head, self.dim_k // self.nums_head)
        V = self.v(x).reshape(x.shape[0], x.shape[1], self.nums_head, self.dim_v // self.nums_head)

        print(x.shape)
        print(Q.shape)

        attn = nn.Softmax(dim=-1)(torch.matmul(Q.permute(0, 2, 1, 3), K.permute(0, 2, 3, 1)) * self._norm_fact)
        print(f"attn_shape = {attn.shape}")
        # batch_size * nums_head * seq_len * seq_len

        # 2 - 8 - 4 - 4 * 2 - 8 - 4 - 4
        output = torch.matmul(attn, V.permute(0, 2, 1, 3))
        print(f"output_shape = {output.shape}")
        # batch_size * nums_head * seq_len * dim_v
        output = output.permute(0, 2, 1, 3)
        output = output.contiguous().view(output.shape[0], output.shape[1], -1)
        return output
    
X = torch.randn(2, 4, 64)
print(X)
multi_head_attention = Multi_Head_Attention(64, 32, 32, 8)
res = multi_head_attention(X)
print(res)
print(res.shape)
