#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <functional>

class Matrix
{
private:
  size_t m_rows{0};
  size_t m_columns{0};
  std::vector<std::vector<double>> m_data;
  
  static size_t validateSize(size_t size);

public:
  Matrix(size_t rows, size_t columns);
  Matrix(const std::vector<std::vector<double>>& data);
  void print() const;
  void print_dim() const;
  size_t get_rows() const;
  size_t get_columns() const;
  std::vector<double> get_col(int i) const;
  Matrix matrix_mul(const Matrix& b) const;
  Matrix matrix_add(const Matrix& b) const;
  Matrix matrix_sub(const Matrix& b) const;
  Matrix hadamard(const Matrix& b) const;
  Matrix matrix_mul_s(double s) const;
  Matrix matrix_sub_s(double s) const;
  Matrix add_vec(std::vector<double>& v, bool to_col) const;
  Matrix apply(std::function<double(double)> f) const;
  Matrix transpose() const;
};

#endif