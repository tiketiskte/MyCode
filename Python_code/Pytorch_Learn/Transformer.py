import torch
import torch.nn as nn
import torch.nn.functional as F

x = torch.randn(128, 64, 512) # batch, time, dimension
print(x.shape)