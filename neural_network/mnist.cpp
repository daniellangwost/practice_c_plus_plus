#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include "matrix.h"
#include "mnist.h"

std::vector<Matrix> load_mnist_images(std::string path, size_t image_count)
{
  std::vector<Matrix> images;
  images.reserve(image_count);

  std::ifstream in;
  in.open(path, std::ios::binary);

  int magic_number = read_int(in);
  if (!(magic_number == 2051)) 
    throw std::invalid_argument("You are trying to read a file without training images!");

  int file_image_count = read_int(in);
  int num_rows = read_int(in);
  int num_cols = read_int(in);

  std::cout << "File contains " << file_image_count << " images with dimensions " << num_rows << " * " << num_cols << "\n";
  

  return images;
}

int read_int(std::ifstream& in)
{
  std::array<u_int8_t, 4> int_buffer;
  int result{0};

  for (size_t i{}; i < 4; ++i)
  {
    in >> int_buffer[i];
  }

  result = (int_buffer[0] << 24) | (int_buffer[1] << 16) | (int_buffer[2] << 8) | int_buffer[3];
  return result;  
}