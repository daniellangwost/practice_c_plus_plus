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
  Matrix();
  Matrix(size_t rows, size_t columns);
  Matrix(const std::vector<std::vector<double>>& data);
  Matrix(std::initializer_list<std::initializer_list<double>> l);
  void print() const;
  void print_dim() const;
  size_t get_rows() const;
  size_t get_columns() const;
  std::vector<double> get_col(size_t i) const;
  Matrix matrix_mul(const Matrix& b) const;
  Matrix matrix_add(const Matrix& b) const;
  Matrix matrix_sub(const Matrix& b) const;
  Matrix hadamard(const Matrix& b) const;
  Matrix matrix_mul_s(double s) const;
  Matrix matrix_sub_s(double s) const;
  Matrix add_vec(std::vector<double>& v, bool to_col) const;
  Matrix apply(std::function<double(double)> f) const;
  void set(size_t row, size_t col, double val);
  double get(size_t row, size_t col);
  Matrix transpose() const;
};

double dot(const std::vector<double>& a, const std::vector<double>& b);

#endif