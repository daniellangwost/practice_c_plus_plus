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

public:
    NN(std::vector<size_t> neuron_counts);
    Matrix feed_forward_with_sigm(Matrix& a);
    std::vector<Matrix> activations_no_sigm(Matrix& a);
    std::pair<std::vector<Matrix>, std::vector<Matrix>> backprop(Matrix& x, Matrix& y);

};

#endif