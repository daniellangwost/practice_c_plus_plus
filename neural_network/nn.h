#ifndef NN_H
#define NN_H

#include <vector>
#include "matrix.h"

class NN
{
private:
    size_t layer_count;
    std::vector<size_t> neuron_counts; 
    // for the following comments, layers start with 1
    std::vector<Matrix> biases; // biases[n] is a matrix(cols=1) with biases of layer n+1
    std::vector<Matrix> weights; // weights[n] is a matrix where (n,m) is the weight for neuron m in layer n+1 to neuron n in layer n+2
    Matrix feed_forward_with_sigm(Matrix& a) const;
    std::vector<Matrix> activations_no_sigm(Matrix& a) const;
    std::vector<Matrix> activations_after_sigm(Matrix& input) const;
    std::pair<std::vector<Matrix>, std::vector<Matrix>> backprop(Matrix& x, Matrix& y) const;
    void update_network(std::vector<std::pair<Matrix, Matrix>> training_data, double learning_rate);
public:
    NN(std::vector<size_t> neuron_counts);
    void train(std::vector<std::pair<Matrix, Matrix>> training_data, int epochs, size_t batch_size, double learning_rate, std::vector<std::pair<Matrix, Matrix>> test_data);
    double test(std::vector<std::pair<Matrix, Matrix>> test_data);
};

#endif