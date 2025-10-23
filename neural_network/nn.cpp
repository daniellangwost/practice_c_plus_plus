#include <iostream>
#include <vector>
#include <cmath>
#include "matrix.h"
#include "nn.h"

std::vector<size_t> validateLayerCount(std::vector<size_t> neuron_counts)
{
    if (neuron_counts.size() < 2)
        throw std::invalid_argument("Network needs at least 2 layers");
    return neuron_counts;
}

NN::NN(std::vector<size_t> neuron_counts)
    : layer_count{neuron_counts.size()}
    , neuron_counts{validateLayerCount(neuron_counts)}
    , biases{std::vector<Matrix>(layer_count-1)}
    , weights{std::vector<Matrix>(layer_count-1)}
{
    for (size_t i{}; i < layer_count-1; ++i)
    {
        biases[i] = Matrix(neuron_counts[i+1], (size_t)1);
        weights[i] = Matrix(neuron_counts[i+1], neuron_counts[i]);
    }
}

Matrix sigmoid(Matrix z) 
{
  size_t row_count = z.get_rows();
  Matrix result(row_count, 1);
  for (size_t i{}; i < row_count; ++i)
  {
    double curr = z.get(i, 0);
    result.set(i, 0, 1/(1+exp(-curr)));
  }
  return result;
}

Matrix NN::feed_forward(Matrix& a) // a' = sigm(wa + b) for each layer with input activation a, output a'
{
  Matrix output{a};
  for (size_t i{}; i < biases.size(); ++i)
  {
    Matrix w = weights[i];
    Matrix& b = biases[i];

    w.matrix_mul(output);
    w.matrix_add(b);

    output = sigmoid(w);
  }
  return output;
}