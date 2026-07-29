import numpy as np

class BP:
    def __init__(self, input_size, hidden_sizes, output_size):
        self.layers = [input_size] + hidden_sizes + [output_size]
        self.W = [np.random.randn(i, self.layers[i], self.layers[i - 1]) for i in range(1, len(self.layers))]
        self.b = [np.random.randn(i, 1, 1) for i in range(1, len(self.layers))]

        self.z = [np.random.randn(i, self.layers[i], 1) for i in range(0, len(self.layers))]
        self.a = [np.random.randn(i, self.layers[i], 1) for i in range(0, len(self.layers))]

    def relu(self, x):
        return np.maximum(0, x)

    def relu_derivative(self, x):
        return np.where(x > 0, 1, 0)

    def forward(self, x):
        self.z[0] = x
        self.a[0] = x
        for i in range(1, len(self.layers)):
            self.z[i] = np.dot(self.W[i], self.a[i - 1]) + self.b[i]
        return self.z
    def get_W_shape(self):
        return [w.shape for w in self.W]

    def get_b_shape(self):
        return [b.shape for b in self.b]

    def get_a_shape(self):
        return [a.shape for a in self.a]
np.random.seed(7521)
input_size = 2
# hidden_sizes = [3, 2]
hidden_sizes = [1]
output_size = 1
MLP = BP(input_size, hidden_sizes, output_size)

print("layers:", MLP.layers)
print("W_shape", MLP.get_W_shape())
print("b_shape", MLP.get_b_shape())
print("a_shape", MLP.get_a_shape())

x = np.array([3, 4])
# print(MLP.forward(x))