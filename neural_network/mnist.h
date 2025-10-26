#ifndef MNIST_H
#define MNIST_H

#include <vector>
#include <iostream>
#include "matrix.h"

std::vector<Matrix> load_mnist_images(std::string path, size_t image_count);
int read_int(std::ifstream& in);
void read_image(Matrix& m, std::ifstream& in);

#endif
