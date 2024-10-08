import torch
from torch import nn
import torch.nn.functional as F
import torch.optim as optim

'''
# RNNcell
batch_size = 1
seqlen = 3
input_size = 4
hidden_size = 2
num_layers = 5
cell1 = nn.RNNCell(input_size=input_size, hidden_size=hidden_size)
# (seq, batch, features)
dataset = torch.randn(seqlen, batch_size, input_size)
hidden = torch.zeros(batch_size, hidden_size)

for idx, input in enumerate(dataset):
    print('=' * 20, idx, '=' * 20)
    print('Input size: ', input.shape)

    out, hidden = cell1(input, hidden)
    print('outputs size: ', hidden.shape)
    print(hidden)
'''

# RNN
batch_size = 1
seqlen = 3
input_size = 4
hidden_size = 2
num_layers = 1
inputs = torch.randn(seqlen, batch_size, input_size)
hidden = torch.zeros(num_layers, batch_size, hidden_size)

cell2 = nn.RNN(input_size = input_size, hidden_size = hidden_size, num_layers = num_layers)
out, hidden = cell2(inputs, hidden)
print('output size:', out.shape)
print('output:',out)
print('hidden size', hidden.shape)
print('hidden:', hidden)