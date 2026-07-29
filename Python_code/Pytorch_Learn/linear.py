import torch
from torch import nn
x = torch.tensor([[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]])
class Mymodel(nn.Module):
    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)
        self.linear = nn.Linear(3, 1)
    def forward(self, x):
        return self.linear(x)

model = Mymodel()
print(x)
y = model(x)
print(model.parameters())
print(y, y.shape)