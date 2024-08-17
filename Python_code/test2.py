# test
import torch
<<<<<<< HEAD
import torch.nn as nn
from torch.nn import functional as F
from torch.nn.parameter import Parameter
from matplotlib import pyplot as plt
import copy
import math
import numpy
=======
import numpy

>>>>>>> eb93c1e8ff4fbd7720f0e5b798ce4d9e36abf8c0
def generate_square_subsequent_mask(sz):
    mask = (torch.triu(torch.ones(sz, sz)) == 1).transpose(0, 1)
    # mask = mask.float().masked_fill(mask==0, float('-inf')).masked_fill(mask==1, float(0.0))
    return mask  # [sz, sz]

ans = generate_square_subsequent_mask(sz=5)
print(ans)
