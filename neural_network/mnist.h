#ifndef MNIST_H
#define MNIST_H

#include <vector>
#include <utility>
#include <iostream>
#include "matrix.h"

std::vector<std::pair<Matrix, Matrix>> load_mnist_images(std::string image_path, std::string label_path, size_t image_count);
int read_int(std::ifstream& in);
void read_image(Matrix& m, std::ifstream& in);
size_t read_label(Matrix& m, std::ifstream& in);

#endif
