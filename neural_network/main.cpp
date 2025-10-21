#include <iostream>
#include "matrix.h"

int main()
{
  Matrix a({
    {1, 2, 3, 4}, 
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  });

  Matrix b({
    {12, 11, 10, 9},
    {8, 7, 6, 5},
    {4, 3, 2, 1}
  });

  Matrix result = a.matrix_add(b);
  result.print();
}