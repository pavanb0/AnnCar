import numpy as np

# Activation functions
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

# Neural Network class
class NeuralNetwork:
    def __init__(self, input_size, hidden_size, output_size):
        # Initialize weights and biases
        self.weights_input_hidden = np.random.uniform(size=(input_size, hidden_size))
        self.bias_hidden = np.zeros((1, hidden_size))
        self.weights_hidden_output = np.random.uniform(size=(hidden_size, output_size))
        self.bias_output = np.zeros((1, output_size))

    def forward(self, X):
        self.hidden_layer_activation = sigmoid(np.dot(X, self.weights_input_hidden) + self.bias_hidden)
        self.output = sigmoid(np.dot(self.hidden_layer_activation, self.weights_hidden_output) + self.bias_output)
        return self.output

    def backward(self, X, y, learning_rate):
        error = y - self.output
        output_delta = error * sigmoid_derivative(self.output)

        hidden_layer_error = output_delta.dot(self.weights_hidden_output.T)
        hidden_layer_delta = hidden_layer_error * sigmoid_derivative(self.hidden_layer_activation)

        self.weights_hidden_output += self.hidden_layer_activation.T.dot(output_delta) * learning_rate
        self.bias_output += np.sum(output_delta, axis=0, keepdims=True) * learning_rate
        self.weights_input_hidden += X.T.dot(hidden_layer_delta) * learning_rate
        self.bias_hidden += np.sum(hidden_layer_delta, axis=0, keepdims=True) * learning_rate

    def train(self, X, y, epochs, learning_rate):
        for epoch in range(epochs):
            output = self.forward(X)
            self.backward(X, y, learning_rate)
            if epoch % 100 == 0:
                loss = np.mean(np.square(y - output))
                print(f"Epoch {epoch}, Loss: {loss}")

input_size = 640 * 480  # Adjust based on your input size
hidden_size = 64        # Adjust based on your network complexity
output_size = 1         # Adjust based on your output size

X = np.random.rand(100, input_size)  # Example data
y = np.random.rand(100, output_size) * 2 - 1  # Random values between -1 and 1

nn = NeuralNetwork(input_size, hidden_size, output_size)
nn.train(X, y, epochs=1000, learning_rate=0.01)
