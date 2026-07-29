import torch
import torchvision.models

# load-1
# model1 = torch.load("./vgg16_method1.pth")
# print(model1)

# load-2
vgg16 = torchvision.models.vgg16(pretrained=False)
vgg16.load_state_dict(torch.load("./vgg16_method2.pth"))
# model2 = torch.load("./vgg16_method2.pth")
# print(vgg16)

# 陷阱 采用方式1 报错 需要将网络结构复制到加载的py文件中
model = torch.load("./self_model.pth")
print(model)
