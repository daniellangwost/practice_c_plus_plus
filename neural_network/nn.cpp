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
  for (size_t layer{layer_count-2}; layer > 0; layer--)
  {
      Matrix current_error = weights[layer+1].transpose();
      current_error = current_error.matrix_mul(errors[layer+1]);
      current_error.hadamard(sigmoid_derivative(activations[layer]));
      errors[layer] = current_error;
  }

  std::vector<Matrix> gradient_biases = errors;
  std::vector<Matrix> gradient_weights;
  gradient_weights.reserve(layer_count-1);

  for (size_t layer_index{1}; layer_index < layer_count; layer_index++)
  {
    size_t rows{neuron_counts[layer_index]};
    size_t cols{neuron_counts[layer_index-1]};
    gradient_weights.push_back(
      Matrix(rows, cols));

    for (size_t j{}; j < rows; ++j)
    {
      for (size_t k{}; k < cols; k++)
      {
        double val = activations[layer_index-1].get(k, 1) * errors[layer_index].get(j, 1);
        gradient_weights[layer_index-1].set(j, k, val);
      }
    }
  }
  return std::pair<std::vector<Matrix>, std::vector<Matrix>>{gradient_weights, gradient_biases};
}

void NN::update_network(
  std::vector<std::pair<Matrix, Matrix>> training_data, double learning_rate)
{

  int batch_size {training_data.size()};

  std::vector<Matrix> avg_gradient_weights;
  std::vector<Matrix> avg_gradient_biases;
  avg_gradient_weights.reserve(layer_count-1);
  avg_gradient_biases.reserve(layer_count-1);

  for (size_t i{}; i < layer_count-1; ++i)
  {
    avg_gradient_weights.push_back(Matrix(neuron_counts[i+1], neuron_counts[i]));
    avg_gradient_biases.push_back(Matrix(neuron_counts[i+1], 1));
  }

  for (std::pair<Matrix, Matrix>& example : training_data)
  {
    Matrix& input = example.first;
    Matrix& desired_output = example.second;
    
    std::pair<std::vector<Matrix>, std::vector<Matrix>> example_gradients = backprop(input, desired_output);
    std::vector<Matrix>& example_gradient_weights = example_gradients.first;
    std::vector<Matrix>& example_gradient_biases = example_gradients.second;

    // add up all the gradients
    for (size_t i{}; i < example_gradient_weights.size(); ++i)
    {
      avg_gradient_weights[i].matrix_add(example_gradient_weights[i]);
      avg_gradient_biases[i].matrix_add(example_gradient_biases[i]);
    }
  }

  // scale gradients by batch size
  for (size_t i{}; i < avg_gradient_biases.size(); ++i)
  {
    avg_gradient_weights[i].matrix_mul_s(1.0/batch_size);
    avg_gradient_biases[i].matrix_mul_s(1.0/batch_size);
  }

  // update weights and biases
  for (int i{}; i < weights.size(); ++i) 
  {
    Matrix diff = avg_gradient_weights[i];
    diff.matrix_mul_s(learning_rate);
    weights[i].matrix_sub(diff);

    diff = avg_gradient_biases[i];
    diff.matrix_mul_s(learning_rate);
    biases[i].matrix_sub(diff);
  }
} 
