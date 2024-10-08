import torch
from torch import nn
import torch.nn.functional as F
import torch.optim as optim
import matplotlib
from matplotlib import pyplot as plt
def show_heatmaps(matrices, xlabel, ylabel, titles=None, figsize=(2.5, 2.5), cmap='Reds'):
    '''显示矩阵热图'''
    num_rows, num_cols = matrices.shape[0], matrices.shape[1]
    fig, axes = plt.subplots(num_rows, num_cols, figsize=figsize, sharex=True, sharey=True, squeeze=False)
    for i, (row_axes, row_matrices) in enumerate(zip(axes, matrices)):
        # print("i", i, (row_axes, row_matrices))
        for j, (ax, matrix) in enumerate(zip(row_axes, row_matrices)):
            # print("j", j, (ax, matrix))
            pcm = ax.imshow(matrix.detach().numpy(), cmap=cmap)
            if i == num_rows - 1:
                ax.set_xlabel(xlabel)
            if j == 0:
                ax.set_ylabel(ylabel)
            if titles:
                ax.set_title(titles[j])
    fig.colorbar(pcm, ax=axes, shrink=0.6)
    plt.show()

n_train = 50
x_train, _ = torch.sort(torch.rand(n_train) * 5)

def f(x):
    return 2 * torch.sin(x) + x ** 0.8

y_train = f(x_train) + torch.normal(0.0, 0.5, (n_train, ))
x_test = torch.arange(0, 5, 0.1)
y_truth = f(x_test)
n_test = len(x_test)

def plot_kernel_reg(y_hat):
    plt.plot(x_test, y_truth, 'x', label='Truth')
    plt.plot(x_test, y_hat, 'x', label='Pred')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.legend()
    plt.xlim([0, 5])
    plt.ylim([-1, 5])
    plt.plot(x_train, y_train, 'o', alpha=0.5)
    plt.show()


y_hat = torch.repeat_interleave(y_train.mean(), n_test)

# plot_kernel_reg(y_hat)

X_repeat = x_test.repeat_interleave(n_train).reshape((-1, n_train))
attention_weights = F.softmax(-(X_repeat - x_train)**2 / 2, dim=1)

y_hat = torch.matmul(attention_weights, y_train)
# plot_kernel_reg(y_hat)
# print(y_hat.shape)

# show_heatmaps(attention_weights.unsqueeze(0).unsqueeze(0), xlabel='Sorted training inputs', ylabel='Sorted testing inputs')

class NWKernelRegression(nn.Module):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.w = nn.Parameter(torch.rand((1, ), requires_grad=True))
    
    def forward(self, queries, keys, values):
        queries = queries.repeat_interleave(keys.shape[1]).reshape((-1, keys.shape[1]))
        print("queries:", queries.shape)
        self.attention_weights = F.softmax(-((queries - keys) * self.w) ** 2 / 2, dim=1)
        print("attention_weights:", attention_weights.shape)
        print("values", values.shape)
        x = torch.bmm(self.attention_weights.unsqueeze(1), values.unsqueeze(-1)).reshape(-1)

        print("x:", x.shape)
        return x

x_tile = x_train.repeat((n_train, 1))
y_tile = y_train.repeat((n_train, 1))
keys = x_tile[(1 - torch.eye(n_train)).type(torch.bool)].reshape((n_train, -1))
values = y_tile[(1 - torch.eye(n_train)).type(torch.bool)].reshape((n_train, -1))

net = NWKernelRegression()
loss = nn.MSELoss(reduction='none')
trainer = optim.SGD(net.parameters(), lr=0.5)

for epoch in range(5):
    trainer.zero_grad()
    l = loss(net(x_train, keys, values), y_train)
    l.sum().backward()
    trainer.step()
    print(f'epoch {epoch + 1}, loss {float(l.sum()):.6f}')

keys = x_train.repeat((n_test, 1))
values = y_train.repeat((n_test, 1))
y_hat = net(x_test, keys, values).unsqueeze(1).detach()
plot_kernel_reg(y_hat)

show_heatmaps(net.attention_weights.unsqueeze(0).unsqueeze(0), xlabel='Sorted training inputs', ylabel='Sorted testing inputs')