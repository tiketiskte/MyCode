# test
import torch
import numpy

def generate_square_subsequent_mask(sz):
    mask = (torch.triu(torch.ones(sz, sz)) == 1).transpose(0, 1)
    # mask = mask.float().masked_fill(mask==0, float('-inf')).masked_fill(mask==1, float(0.0))
    return mask  # [sz, sz]

ans = generate_square_subsequent_mask(sz=5)
print(ans)
