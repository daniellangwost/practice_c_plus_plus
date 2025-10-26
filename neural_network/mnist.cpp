#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include "matrix.h"
#include "mnist.h"

std::vector<std::pair<Matrix, Matrix>> load_mnist_images(std::string image_path, std::string label_path, size_t image_count)
{
  std::vector<std::pair<Matrix, Matrix>> images;
  images.reserve(image_count);

  std::ifstream img_stream;
  std::ifstream label_stream;
  img_stream.open(image_path, std::ios::binary);
  label_stream.open(label_path, std::ios::binary);

  if (!img_stream || !label_stream)
    throw std::runtime_error("File could not be opened!\n");

  int magic_number = read_int(img_stream);
  if (!(magic_number == 2051)) 
    throw std::invalid_argument("You are trying to read a file without training images!");
  
  magic_number = read_int(label_stream);
  if (!(magic_number == 2049)) 
    throw std::invalid_argument("You are trying to read a file without labels!");

  int file_image_count = read_int(img_stream);
  int file_label_count = read_int(label_stream);
  if (file_label_count != file_image_count) throw std::invalid_argument("Number of images does not match number of labels");

  size_t num_rows = static_cast<size_t>(read_int(img_stream));
  size_t num_cols = static_cast<size_t>(read_int(img_stream));

  std::cout << "Image file contains " << file_image_count << " images with dimensions " << num_rows << " * " << num_cols << "\n";

  Matrix image(num_rows * num_cols, 1);
  Matrix label(10, 1);
  std::cout << "Created temporary image Matrix with " << num_rows*num_cols << " rows and 1 cols\n";
  std::cout << "Created temporary label Matrix with 10 rows and 1 cols\n";


  size_t index;
  for (size_t i{}; i < image_count; ++i)
  {
    std::cout << "Reading image " << i << "\n";
    read_image(image, img_stream);
    index = read_label(label, label_stream);
    images.push_back({image, label});
    label.set(index, 0, 0);
  }
  img_stream.close();
  label_stream.close();
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

  // conversion from big-endian to little-endian, dataset is in big-endian
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

size_t read_label(Matrix& m, std::ifstream& in)
{
  char buffer;
  u_int8_t val;

  if(!in.read(&buffer, 1))
    throw std::runtime_error("Could not read byte from file\n");
    
  val = static_cast<u_int8_t>(buffer);
  m.set(val, 0, 1);
  return static_cast<size_t>(val);
}