import torch
import numpy as np


Y = torch.LongTensor([2, 0, 1])
Y_pred1 = torch.Tensor([[0.1, 0.2, 0.9],
                        [1.1, 0.1, 0.2],
                        [0.2, 2.1, 0.1]])

criterion = torch.nn.CrossEntropyLoss()
l1 = criterion(Y_pred1, Y)
print(torch.max(Y_pred1, dim=1))