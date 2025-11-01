#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include "matrix.h"
#include "nn.h"
#include "main.h"
#include "mnist.h"

int main()
{
  const int TRAINING_IMAGE_COUNT = 1000;
  const int TEST_IMAGE_COUNT = 20;

  // vector of pairs,first element is a 784x1 Matrix with normalized greyscale image data, second element is a 10x1 Matrix with a 1 in the row indicating the correct label
  std::vector<std::pair<Matrix, Matrix>> training_data = load_mnist_images("data/train.idx3-ubyte","data/train-labels.idx1-ubyte", TRAINING_IMAGE_COUNT);

  // vector of pairs,first element is a 784x1 Matrix with normalized greyscale image data, second element is a 10x1 Matrix with a 1 in the row indicating the correct label
  std::vector<std::pair<Matrix, Matrix>> test_data = load_mnist_images("data/test.idx3-ubyte","data/test-labels.idx1-ubyte", TEST_IMAGE_COUNT);

  NN network({784, 30, 10});
  network.train(training_data, 30, 10, 1.0, test_data);
}