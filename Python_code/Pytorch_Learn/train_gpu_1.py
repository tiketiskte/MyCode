import torch
import torchvision
from torch import nn
from torch.utils.data import DataLoader


from torch.nn import Conv2d, MaxPool2d, Flatten, Linear

# 准备数据集
train_data = torchvision.datasets.CIFAR10(root='./dataset', train=True, transform=torchvision.transforms.ToTensor(),
                                          download=True)
test_data = torchvision.datasets.CIFAR10(root='./dataset', train=False, transform=torchvision.transforms.ToTensor(),
                                         download=True)
class net(nn.Module):
    def __init__(self):
        super(net, self).__init__()
        self.model = nn.Sequential(
            Conv2d(in_channels=3, out_channels=32, kernel_size=5, padding=2),
            MaxPool2d(kernel_size=2),
            Conv2d(in_channels=32, out_channels=32, kernel_size=5, padding=2),
            MaxPool2d(kernel_size=2),
            Conv2d(in_channels=32, out_channels=64, kernel_size=5, padding=2),
            MaxPool2d(kernel_size=2),
            Flatten(),
            Linear(in_features=64 * 4 * 4, out_features=64),
            Linear(in_features=64, out_features=10)
        )

    def forward(self, x):
        x = self.model(x)
        return x


# length长度
train_data_size = len(train_data)
test_data_size = len(test_data)
print(train_data_size, test_data_size)
# 利用DataLoader加载数据集
train_loader = DataLoader(train_data, batch_size=64, shuffle=True)
test_loader = DataLoader(test_data, batch_size=64)
# 创建网络模型
model = net().cuda()
# 损失函数
loss_fn = nn.CrossEntropyLoss()
loss_fn = loss_fn.cuda()
# 优化器
learning_rate = 0.01
optimizer = torch.optim.SGD(model.parameters(), lr=learning_rate)

# 设置训练网络的一些参数
# 记录训练的次数
total_train_step = 0
# 记录测试的次数
total_test_step = 0
# 训练轮数
epoch = 10


for i in range(epoch):
    print("--------第{}论训练开始--------".format(i + 1))
    # 训练开始
    model.train()
    for data in train_loader:
        imgs, targets = data
        imgs = imgs.cuda()
        targets = targets.cuda()
        output = model(imgs)
        loss = loss_fn(output, targets)
        # 优化器优化模型
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        total_train_step += 1
        if total_train_step % 100 == 0:
            print("训练次数:{}, Loss:{}".format(total_train_step, loss.item()))  # item是标准写法
    # 测试步骤开始
    model.eval()
    total_test_loss = 0
    total_accuracy = 0
    with torch.no_grad():
        for data in test_loader:
            imgs, targets = data
            imgs = imgs.cuda()
            targets = targets.cuda()
            output = model(imgs)
            loss = loss_fn(output, targets)
            total_test_loss += loss.item()
            accuracy = (output.argmax(1) == targets).sum()
            total_accuracy += accuracy
    print("整体测试集上的Loss:{}".format(total_test_loss))
    print("整体测试集上的正确率:{}".format(total_accuracy / test_data_size))
    total_test_loss += 1
    # torch.save(model, "./model_{}.pth".format(i + 1))
    # print("模型已保存")