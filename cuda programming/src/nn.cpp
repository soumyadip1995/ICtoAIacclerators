
#include <iostream>
#include <vector>
#include <cmath>

// Activation function (sigmoid)
double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

// Derivative of the activation function (sigmoid derivative)
double sigmoidDerivative(double x) {
    double s = sigmoid(x);
    return s * (1.0 - s);
}

class NeuralNetwork {
private:
    int inputSize;
    int hiddenSize;
    int outputSize;
    std::vector<std::vector<double>> weightsInputHidden;
    std::vector<std::vector<double>> weightsHiddenOutput;
    std::vector<double> hiddenLayer;
    std::vector<double> outputLayer;
    double learningRate;

public:
    NeuralNetwork(int inputSize, int hiddenSize, int outputSize, double learningRate)
        : inputSize(inputSize), hiddenSize(hiddenSize), outputSize(outputSize), learningRate(learningRate) {

        // Initialize weights with random values (you can also use other initialization methods)
        weightsInputHidden.resize(inputSize, std::vector<double>(hiddenSize));
        weightsHiddenOutput.resize(hiddenSize, std::vector<double>(outputSize));

        for (int i = 0; i < inputSize; ++i) {
            for (int j = 0; j < hiddenSize; ++j) {
                weightsInputHidden[i][j] = (std::rand() % 100) / 100.0;
            }
        }

        for (int i = 0; i < hiddenSize; ++i) {
            for (int j = 0; j < outputSize; ++j) {
                weightsHiddenOutput[i][j] = (std::rand() % 100) / 100.0;
            }
        }

        // Initialize hidden and output layer with zeros
        hiddenLayer.resize(hiddenSize, 0.0);
        outputLayer.resize(outputSize, 0.0);
    }

    // Forward pass
    std::vector<double> predict(const std::vector<double>& input) {
        // Check if the input size matches the input layer size
        if (input.size() != inputSize) {
            std::cerr << "Input size does not match the input layer size." << std::endl;
            return {};
        }

        // Compute hidden layer values
        for (int i = 0; i < hiddenSize; ++i) {
            double sum = 0.0;
            for (int j = 0; j < inputSize; ++j) {
                sum += input[j] * weightsInputHidden[j][i];
            }
            hiddenLayer[i] = sigmoid(sum);
        }

        // Compute output layer values
        for (int i = 0; i < outputSize; ++i) {
            double sum = 0.0;
            for (int j = 0; j < hiddenSize; ++j) {
                sum += hiddenLayer[j] * weightsHiddenOutput[j][i];
            }
            outputLayer[i] = sigmoid(sum);
        }

        return outputLayer;
    }

    // Backpropagation and weight updates
    void train(const std::vector<double>& input, const std::vector<double>& target) {
        // Check if the input and target size match the input and output layer size, respectively
        if (input.size() != inputSize || target.size() != outputSize) {
            std::cerr << "Input or target size does not match the input or output layer size." << std::endl;
            return;
        }

        // Forward pass to compute hidden and output layer values
        predict(input);

        // Backpropagation
        std::vector<double> outputErrors(outputSize, 0.0);
        std::vector<double> hiddenErrors(hiddenSize, 0.0);

        // Compute output layer errors
        for (int i = 0; i < outputSize; ++i) {
            outputErrors[i] = (target[i] - outputLayer[i]) * sigmoidDerivative(outputLayer[i]);
        }

        // Compute hidden layer errors
        for (int i = 0; i < hiddenSize; ++i) {
            double error = 0.0;
            for (int j = 0; j < outputSize; ++j) {
                error += outputErrors[j] * weightsHiddenOutput[i][j];
            }
            hiddenErrors[i] = error * sigmoidDerivative(hiddenLayer[i]);
        }

        // Update weights from hidden to output layer
        for (int i = 0; i < hiddenSize; ++i) {
            for (int j = 0; j < outputSize; ++j) {
                weightsHiddenOutput[i][j] += learningRate * outputErrors[j] * hiddenLayer[i];
            }
        }

        // Update weights from input to hidden layer
        for (int i = 0; i < inputSize; ++i) {
            for (int j = 0; j < hiddenSize; ++j) {
                weightsInputHidden[i][j] += learningRate * hiddenErrors[j] * input[i];
            }
        }
    }
};

int main() {
    // Set random seed for weight initialization
    std::srand(42);

    // Create a neural network with 2 input neurons, 3 hidden neurons, and 1 output neuron
    NeuralNetwork neuralNetwork(2, 3, 1, 0.1);

    // Training data
    std::vector<std::vector<double>> trainingInputs = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
    std::vector<std::vector<double>> trainingTargets = { {0}, {1}, {1}, {0} };

    // Training loop
    for (int epoch = 0; epoch < 10000; ++epoch) {
        for (size_t i = 0; i < trainingInputs.size(); ++i) {
            neuralNetwork.train(trainingInputs[i], trainingTargets[i]);
        }
    }

    // Test the trained network
    for (size_t i = 0; i < trainingInputs.size(); ++i) {
        const std::vector<double>& input = trainingInputs[i];
        const std::vector<double>& target = trainingTargets[i];

        std::cout << "Input: " << input[0] << ", " << input[1] << " | ";
        std::cout << "Target: " << target[0] << " | ";
        std::cout << "Output: " << neuralNetwork.predict(input)[0] << std::endl;
    }

    return 0;
}
