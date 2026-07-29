import numpy as np
import torchvision
from matplotlib import pyplot as plt
from torchvision.transforms import transforms


# input layer：784 nodes;
# hidden layer：one hidden layers with 20 nodes in each layer
# output layer：10 nodes

def sigmoid(x):
    return 1 / (1 + np.exp(-x))


def sigmoid_derivative(x):
    return x * (1 - x)
    # return sigmoid(x) * (1 - sigmoid(x))


class BP:
    def __init__(self):
        self.input = np.zeros((100, 784))
        self.hidden_layer = np.zeros((100, 20))
        self.output_layer = np.zeros((100, 10))
        self.w1 = 2 * np.random.random((784, 20)) - 1  # limit to (-1, 1)
        self.w2 = 2 * np.random.random((20, 10)) - 1
        self.error = np.zeros(10)
        self.learning_rate = 0.1

    def forward_prop(self, data, label):
        self.input = data
        self.hidden_layer = sigmoid(np.dot(self.input, self.w1))
        self.output_layer = sigmoid(np.dot(self.hidden_layer, self.w2))
        self.error = (self.output_layer - label)
        loss = np.mean(np.square(self.error))  # 计算均方误差
        return self.output_layer, loss

    def backward_prop(self):
        output_diff = self.error * sigmoid_derivative(self.output_layer)
        hidden_diff = np.dot(output_diff, self.w2.T) * sigmoid_derivative(self.hidden_layer)
        self.w2 -= self.learning_rate * np.dot(self.hidden_layer.T, output_diff)
        self.w1 -= self.learning_rate * np.dot(self.input.T, hidden_diff)


def load_data():
    datasets_train = torchvision.datasets.FashionMNIST(root='D://Py_Code/Pytorch_Learn/FashionMNIST', train=True,
                                                       transform=transforms.ToTensor(), download=True)
    datasets_test = torchvision.datasets.FashionMNIST(root='D://Py_Code/Pytorch_Learn/FashionMNIST', train=False,
                                                      transform=transforms.ToTensor(), download=True)
    X_train = datasets_train.data.numpy()
    X_test = datasets_test.data.numpy()
    X_train = np.reshape(X_train, (60000, 784))
    X_test = np.reshape(X_test, (10000, 784))
    Y_train = datasets_train.targets.numpy()
    Y_test = datasets_test.targets.numpy()
    real_train_y = np.zeros((60000, 10))
    real_test_y = np.zeros((10000, 10))
    for i in range(60000):
        real_train_y[i, Y_train[i]] = 1
    for i in range(10000):
        real_test_y[i, Y_test[i]] = 1
    index = np.arange(60000)
    np.random.shuffle(index)
    X_train = X_train[index]
    real_train_y = real_train_y[index]
    X_train = np.int64(X_train > 0)
    X_test = np.int64(X_test > 0)
    return X_train, real_train_y, X_test, real_test_y


train_losses = []


def BP_network():
    nn = BP()
    X_train, Y_train, X_test, Y_test = load_data()
    batch_size = 100
    epochs = 6000
    for epoch in range(epochs):
        start = (epoch % 600) * batch_size
        end = start + batch_size
        print("Epoch: ", epoch)
        # print("start:{}, end:{} ".format(start, end))
        _, loss = nn.forward_prop(X_train[start: end], Y_train[start: end])
        train_losses.append(loss.item())
        nn.backward_prop()
        if epoch % 10 == 0:
            print("Epoch: {}, Loss: {}".format(epoch, loss))
    # print(nn.w1)
    return nn


def BP_test():
    nn = BP_network()
    sum = 0
    X_train, Y_train, X_test, Y_test = load_data()
    for i in range(len(X_test)):
        res, loss = nn.forward_prop(X_test[i], Y_test[i])
        res = res.tolist()
        index = res.index(max(res))
        if Y_test[i, index] == 1:
            sum += 1
    print("accuracy: ", sum / len(Y_test))


if __name__ == "__main__":
    BP_test()
    fig = plt.figure()
    plt.plot(train_losses, color="blue", label="training loss")
    plt.show()
