
#include <iostream>
#include <vector>
#include <cmath>
#include <cuda_runtime.h>

// ... (include the rest of your NeuralNetwork class and CUDA kernel here)

void testBackpropagationKernel() {
    // Set random seed for weight initialization
    std::srand(42);

    // Create a neural network with 2 input neurons, 3 hidden neurons, and 1 output neuron
    int inputSize = 2;
    int hiddenSize = 3;
    int outputSize = 1;
    double learningRate = 0.1;
    NeuralNetwork neuralNetwork(inputSize, hiddenSize, outputSize, learningRate);

    // Sample test data
    std::vector<double> input = {0.5, 0.8};
    std::vector<double> target = {0.9};

    // Perform the backpropagation using the CUDA kernel
    neuralNetwork.trainCUDA(input, target);

    // Display the updated weights after training
    std::cout << "Weights (Input to Hidden) after training:" << std::endl;
    for (int i = 0; i < inputSize; ++i) {
        for (int j = 0; j < hiddenSize; ++j) {
            std::cout << neuralNetwork.getWeightInputHidden(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Weights (Hidden to Output) after training:" << std::endl;
    for (int i = 0; i < hiddenSize; ++i) {
        for (int j = 0; j < outputSize; ++j) {
            std::cout << neuralNetwork.getWeightHiddenOutput(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    testBackpropagationKernel();
    return 0;
}
