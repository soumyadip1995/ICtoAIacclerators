
%%cu


#include <iostream>
#include <vector>
#include <cmath>
#include <cuda_runtime.h>

// Activation function (sigmoid)
__device__ double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Derivative of the activation function (sigmoid derivative)
__device__ double sigmoidDerivative(double x) {
    double s = sigmoid(x);
    return s * (1.0 - s);
}

// CUDA kernel for weight update
__global__ void backpropagationKernel(double* input, double* hiddenLayer, double* outputLayer,
                                      double* target, double* weightsInputHidden, double* weightsHiddenOutput,
                                      double learningRate, int inputSize, int hiddenSize, int outputSize) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < inputSize && col < hiddenSize) {
        double gradient = 0.0;
        for (int i = 0; i < outputSize; ++i) {
            double outputError = target[i] - outputLayer[i];
            gradient += outputError * sigmoidDerivative(outputLayer[i]) * weightsHiddenOutput[col * outputSize + i];
        }
        weightsInputHidden[row * hiddenSize + col] += learningRate * gradient * sigmoidDerivative(hiddenLayer[col]) * input[row];
    }

    if (row < hiddenSize && col < outputSize) {
        double outputError = target[col] - outputLayer[col];
        weightsHiddenOutput[row * outputSize + col] += learningRate * outputError * sigmoidDerivative(outputLayer[col]) * hiddenLayer[row];
    }
}

class NeuralNetwork {
private:
    // ... (rest of the code remains the same)

public:
    // ... (rest of the code remains the same)

    // CUDA backpropagation pass
    void trainCUDA(const std::vector<double>& input, const std::vector<double>& target) {
        // Check if the input and target size match the input and output layer size, respectively
        if (input.size() != inputSize || target.size() != outputSize) {
            std::cerr << "Input or target size does not match the input or output layer size." << std::endl;
            return;
        }

        // Allocate device memory
        double* d_input;
        double* d_hiddenLayer;
        double* d_outputLayer;
        double* d_target;
        double* d_weightsInputHidden;
        double* d_weightsHiddenOutput;

        cudaMalloc((void**)&d_input, inputSize * sizeof(double));
        cudaMalloc((void**)&d_hiddenLayer, hiddenSize * sizeof(double));
        cudaMalloc((void**)&d_outputLayer, outputSize * sizeof(double));
        cudaMalloc((void**)&d_target, outputSize * sizeof(double));
        cudaMalloc((void**)&d_weightsInputHidden, inputSize * hiddenSize * sizeof(double));
        cudaMalloc((void**)&d_weightsHiddenOutput, hiddenSize * outputSize * sizeof(double));

        // Copy data to device
        cudaMemcpy(d_input, input.data(), inputSize * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(d_hiddenLayer, hiddenLayer.data(), hiddenSize * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(d_outputLayer, outputLayer.data(), outputSize * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(d_target, target.data(), outputSize * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(d_weightsInputHidden, weightsInputHidden.data(), inputSize * hiddenSize * sizeof(double), cudaMemcpyHostToDevice);
        cudaMemcpy(d_weightsHiddenOutput, weightsHiddenOutput.data(), hiddenSize * outputSize * sizeof(double), cudaMemcpyHostToDevice);

        // Define the grid and block dimensions
        dim3 threadsPerBlock(32, 1);
        dim3 numBlocks((hiddenSize + threadsPerBlock.x - 1) / threadsPerBlock.x, 1);

        // Call the CUDA kernel
        backpropagationKernel<<<numBlocks, threadsPerBlock>>>(d_input, d_hiddenLayer, d_outputLayer, d_target,
                                                              d_weightsInputHidden, d_weightsHiddenOutput,
                                                              learningRate, inputSize, hiddenSize, outputSize);

        // Copy updated weights back to the host
        cudaMemcpy(weightsInputHidden.data(), d_weightsInputHidden, inputSize * hiddenSize * sizeof(double), cudaMemcpyDeviceToHost);
        cudaMemcpy(weightsHiddenOutput.data(), d_weightsHiddenOutput, hiddenSize * outputSize * sizeof(double), cudaMemcpyDeviceToHost);

        // Free device memory
        cudaFree(d_input);
        cudaFree(d_hiddenLayer);
        cudaFree(d_outputLayer);
        cudaFree(d_target);
        cudaFree(d_weightsInputHidden);
        cudaFree(d_weightsHiddenOutput);
    }
};

int main() {
    // ... (rest of the code remains the same)
}
