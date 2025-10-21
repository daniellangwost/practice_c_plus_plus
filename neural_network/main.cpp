#include <iostream>
#include <functional>
#include <cmath>
#include "matrix.h"
#include "nn.h"

int main()
{
  NN n({2, 3, 1});
}

Matrix sigmoid(Matrix z)
{
  Matrix result(z.get_rows(), 1);
  for (auto row : z.get_col(0))
  {
    result[0]
  }
}