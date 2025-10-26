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
  if (!in)
    throw std::runtime_error("File could not be opened!\n");

  int magic_number = read_int(in);
  if (!(magic_number == 2051)) 
    throw std::invalid_argument("You are trying to read a file without training images!");

  int file_image_count = read_int(in);
  size_t num_rows = static_cast<size_t>(read_int(in));
  size_t num_cols = static_cast<size_t>(read_int(in));

  std::cout << "File contains " << file_image_count << " images with dimensions " << num_rows << " * " << num_cols << "\n";

  Matrix image(num_rows * num_cols, 1);
  std::cout << "Created temporary image Matrix with " << num_rows*num_cols << " rows and 1 cols\n";
  for (size_t i{}; i < image_count; ++i)
  {
    std::cout << "Reading image " << i << "\n";
    read_image(image, in);
    images.push_back(image);
  }

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

void read_image(Matrix& m, std::ifstream& in)
{
  char buffer;
  u_int8_t val;
  for (size_t i{}; i < m.get_rows() * m.get_columns(); ++i)
  {
    if(!in.read(&buffer, 1))
      throw std::runtime_error("Could not read byte from file\n");
      
    val = static_cast<u_int8_t>(buffer);
    m.set(i, 0, static_cast<double>(val) / 255.0);
  }
}