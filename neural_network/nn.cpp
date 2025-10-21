#include <iostream>
#include <vector>
#include "matrix.h"
#include "nn.h"

std::vector<int> validateLayerCount(std::vector<int> neuron_counts)
{
    if (neuron_counts.size() < 2)
        throw std::invalid_argument("Network needs at least 2 layers");
    return neuron_counts;
}

NN::NN(std::vector<int> neuron_counts)
    : layer_count{static_cast<int>(neuron_counts.size())}
    , neuron_counts{validateLayerCount(neuron_counts)}
    , biases{std::vector<Matrix>(layer_count-1)}
    , weights{std::vector<Matrix>(layer_count-1)}
{
    for (int i{}; i < layer_count-1; ++i)
    {
        biases[i] = Matrix(neuron_counts[i+1], 1);
        weights[i] = Matrix(neuron_counts[i+1], neuron_counts[i]);
    }
}