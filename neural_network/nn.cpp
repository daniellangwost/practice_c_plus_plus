#include <iostream>
#include <vector>
#include <cmath>
#include <random>
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

  std::random_device rd;
  std::mt19937 gen(rd());

  for (size_t l{}; l < layer_count-1; ++l)
  {
    biases[l] = Matrix(neuron_counts[l+1], (size_t)1);

    size_t rows = neuron_counts[l+1];
    size_t cols = neuron_counts[l];
    weights[l] = Matrix(rows, cols);

    std::normal_distribution<double> dist(0.0, 0.01);

    for (size_t i{}; i < rows; ++i)
    {
      for (size_t j{}; j < cols; ++j)
      {
        weights[l].set(i, j, dist(gen));
      }
    }
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

Matrix sigmoid_derivative(Matrix z)
{
  Matrix result = sigmoid(z); // result = sigm(z)
  Matrix temp = result;
  temp.matrix_mul_s(-1); // result = -sigm(z)
  temp.matrix_sub_s(-1); // result = 1-sigm(z)

  result.hadamard(temp);
  return result;
}

// returns lists of gradients for weights and biases
std::pair<std::vector<Matrix>, std::vector<Matrix>> NN::backprop(Matrix& input, Matrix& desired_output) const
{
  std::vector<Matrix> z_values;
  std::vector<Matrix> a_values;
  z_values.reserve(layer_count-1);
  a_values.reserve(layer_count);

  a_values.push_back(input);

  Matrix curr_activations = input;
  for (size_t i{}; i < layer_count-1; ++i)
  {
    Matrix z = weights[i].matrix_mul(curr_activations);
    z.matrix_add(biases[i]);
    z_values.push_back(z);
    
    curr_activations = sigmoid(z);
    a_values.push_back(curr_activations);
  }

  // feed forward to arrive at list of output activations
  Matrix output_error = a_values[a_values.size()-1];
  output_error.matrix_sub(desired_output);
  output_error.hadamard(sigmoid_derivative(z_values[z_values.size()-1]));

  std::vector<Matrix> errors(layer_count-1);
  errors[errors.size() - 1] = output_error;


  // loop backwards over layers L-1 to 2, calculate error
  for (size_t layer{layer_count-2}; layer > 0; layer--)
  {
      Matrix current_error = weights[layer].transpose();
      current_error = current_error.matrix_mul(errors[layer]);
      current_error.hadamard(sigmoid_derivative(z_values[layer-1]));
      errors[layer-1] = current_error;
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
        double val = a_values[layer_index-1].get(k, 0) * errors[layer_index-1].get(j, 0);
        gradient_weights[layer_index-1].set(j, k, val);
      }
    }
  }
  return std::pair<std::vector<Matrix>, std::vector<Matrix>>{gradient_weights, gradient_biases};
}

void NN::update_network(
  std::vector<std::pair<Matrix, Matrix>> training_data, double learning_rate)
{

  int batch_size = static_cast<int>(training_data.size());

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
  for (size_t i{}; i < weights.size(); ++i) 
  {
    Matrix diff = avg_gradient_weights[i];
    diff.matrix_mul_s(learning_rate);
    weights[i].matrix_sub(diff);

    diff = avg_gradient_biases[i];
    diff.matrix_mul_s(learning_rate);
    biases[i].matrix_sub(diff);
  }
} 

void NN::train(std::vector<std::pair<Matrix, Matrix>> training_data, int epochs, size_t batch_size, double learning_rate, std::vector<std::pair<Matrix, Matrix>> test_data = {})
{
  std::cout << "Training started!\n";
  size_t training_data_size = training_data.size();

  std::random_device rd;
  std::mt19937 gen(rd());

  for (int epoch{}; epoch < epochs; ++epoch)
  {
    size_t batch_count = training_data_size / batch_size;
    std::shuffle(training_data.begin(), training_data.end(), gen);
    for (size_t i{}; i < batch_count; ++i)
    {
      std::vector<std::pair<Matrix, Matrix>> batch_data;
      batch_data.reserve(batch_size);
      for (size_t j{}; j < batch_size; ++j)
      {
        batch_data.push_back(training_data[i * batch_size + j]);
      }
      update_network(batch_data, learning_rate);
    }
    size_t remaining_data = training_data_size % batch_size;
    if (remaining_data > 0)
    {
      std::vector<std::pair<Matrix, Matrix>> batch_data;
      batch_data.reserve(remaining_data);
      for (size_t i{training_data_size - remaining_data}; i < training_data_size; i++)
      {
        batch_data.push_back(training_data[i]);
      }
      update_network(batch_data, learning_rate);
    }
    std::cout << "Epoch " << epoch << ": ";
    if (!test_data.empty())
    {
      double percent_correct = test(test_data);
      std::cout << "Accuracy: " << percent_correct << "%\n";
    }
    else
    {
      std::cout << "\n";
    }
  }
}

double NN::test(std::vector<std::pair<Matrix, Matrix>> test_data)
{
  int correct_count{};
  for (auto& test : test_data)
  {
    Matrix& input = test.first;
    Matrix& correct_output = test.second;

    Matrix network_output = feed_forward_with_sigm(input);
    size_t max_index_correct_output{};

    size_t max_index_network_output{};
    double max_value_network_output{network_output.get(0, 0)};

    for (size_t i{}; i < neuron_counts[layer_count-1]; ++i)
    {
      if (correct_output.get(i, 0) == 1) max_index_correct_output = i;

      if (network_output.get(i, 0) > max_value_network_output)
      {
        max_value_network_output = network_output.get(i, 0);
        max_index_network_output = i;
      }
    }
    if (max_index_correct_output == max_index_network_output) correct_count++;
  }
  
  return ((double)correct_count / (double)test_data.size()) * 100;
}