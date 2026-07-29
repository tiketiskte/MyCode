import torch
import torchvision
from torch import nn
from torch.nn import ReLU, Sigmoid
from torch.utils.data import DataLoader
from torch.utils.tensorboard import SummaryWriter

input = torch.tensor([[1., -0.5],
                      [-1, 3]])
input = torch.reshape(input, (-1, 1, 2, 2))

dataset = torchvision.datasets.CIFAR10(root='./dataset', train=True, transform=torchvision.transforms.ToTensor(),
                                       download=True)
dataloader = DataLoader(dataset, batch_size=64)

class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.relu1 = ReLU()
        self.sigmoid1 = Sigmoid()

    def forward(self, input):
        output = self.sigmoid1(input)
        return output

net = Net()
step = 0
writer = SummaryWriter('logs')
for data in dataloader:
    imgs, targets = data
    writer.add_images('input', imgs, step)
    output = net(imgs)
    writer.add_images('output', output, step)
    step += 1
    if step > 10:
        break
writer.close()
