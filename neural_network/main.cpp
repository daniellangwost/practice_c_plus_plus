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
  const int TRAINING_IMAGE_COUNT = 60000;
  const int TEST_IMAGE_COUNT = 10000;

  std::vector<Matrix> training_data = load_mnist_images("data/train.idx3-ubyte", TRAINING_IMAGE_COUNT);
  std::vector<Matrix> test_data = load_mnist_images("data/test.idx3-ubyte", TEST_IMAGE_COUNT);

}