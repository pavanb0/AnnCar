import numpy as np 
np.random.seed(45)
weights = np.random.rand(3,1)
bias = np.random.rand(1)
lr = 0.05
# print(weights) 

inputDataSet = np.array([[0,1,0],
                      [0,0,1],
                      [1,0,0],
                      [1,1,0],
                      [1,1,1],
                      [0,1,1],
                      [0,1,0]])
labels = np.array([[
    1,
    0,
    0,
    1,
    1,
    0,
    1
]])
labels = labels.reshape(7,1)
# print(labels)
def sigmoid(x):
    return 1/(1+np.exp(-x))

def sigmoid_derivative(x):
    return sigmoid(x)*(1-sigmoid(x))


