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

Matrix sigmoid(Matrix& z) 
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

// a' = sigm(wa + b) for each layer with input activation a, output a'
Matrix NN::feed_forward_with_sigm(Matrix& a)
{
  Matrix output{a};
  for (size_t i{}; i < biases.size(); ++i)
  {
    Matrix& b = biases[i];

    Matrix z = weights[i].matrix_mul(output);
    z.matrix_add(b);

    output = sigmoid(z);
  }
  return output;
}

std::vector<Matrix> NN::activations_no_sigm(Matrix& input) // TESTED
{
  std::vector<Matrix> activations(layer_count);
  activations[0] = input;

  // i is the layer index from with the activations are currently passed forward
  for (size_t i{}; i < layer_count - 1; ++i)
  {
    Matrix& b = biases[i];
    Matrix z = weights[i].matrix_mul(activations[i]);
    z.matrix_add(b);
    activations[i+1] = z;
  }
  return activations;
}

Matrix sigmoid_derivative(Matrix z)
{
  Matrix result = sigmoid(z); // result = sigm(z)
  result.matrix_mul_s(-1); // result = -sigm(z)
  result.matrix_sub_s(-1); // result = 1-sigm(z)

  return sigmoid(z).matrix_mul(result);
}

// returns lists of gradients for weights and biases
std::pair<std::vector<Matrix>, std::vector<Matrix>> NN::backprop(Matrix& input, Matrix& desired_output)
{

  std::vector<Matrix> activations = activations_no_sigm(input);

  // feed forward to arrive at list of output activations
  Matrix output_error = feed_forward_with_sigm(input);
  Matrix output_no_sigm = activations[activations.size() - 1];

  output_error.matrix_sub(desired_output);
  output_error.hadamard(sigmoid_derivative(output_no_sigm));
  
  std::vector<Matrix> errors(layer_count-1);
  errors[errors.size() - 1] = output_error;

  // loop backwards over layers L-1 to 2, calculate error
  for (int layer{layer_count-2}; layer > 0; layer--)
  {
      Matrix current_error = weights[layer+1].transpose();
      current_error = current_error.matrix_mul(errors[layer+1]);
      current_error.hadamard(sigmoid_derivative(activations[layer]));
      errors[layer] = current_error;
  }

  std::vector<Matrix> gradient_biases = errors;
  std::vector<Matrix> gradient_weights;
  gradient_weights.reserve(layer_count-1);

  for (int layer_index{1}; layer_index < layer_count; layer_index++)
  {
    size_t rows{neuron_counts[layer_index]};
    size_t cols{neuron_counts[layer_index-1]};
    gradient_weights.push_back(
      Matrix(rows, cols));

    for (int j{}; j < rows; ++j)
    {
      for (int k{}; k < cols; k++)
      {
        double val = activations[layer_index-1].get(k, 1) * errors[layer_index].get(j, 1);
        gradient_weights[layer_index-1].set(j, k, val);
      }
    }
  }
  return std::pair<std::vector<Matrix>, std::vector<Matrix>>{gradient_weights, gradient_biases};
}
