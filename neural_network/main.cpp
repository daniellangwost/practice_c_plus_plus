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
  // NN net({2, 3, 1});

  std::vector<Matrix> x = load_mnist_images("train-images.idx3-ubyte", 1);

}