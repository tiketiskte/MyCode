import torch
import torchvision
from torch import nn

# save-1 网络模型结构 + 模型参数
vgg = torchvision.models.vgg16(weights=None)
torch.save(vgg, "vgg16_method1.pth")

# save-2 模型参数(网络模型参数以字典形式保存) 官方推荐
torch.save(vgg.state_dict(), "vgg16_method2.pth")


# 陷阱 采用方式1
class net(nn.Module):
    def __init__(self):
        super(net, self).__init__()
        self.conv1 = nn.Conv2d(3, 64, kernel_size=3)

    def forward(self, x):
        x = self.conv1(x)
        return x


model = net()
torch.save(model, "self_model.pth")
