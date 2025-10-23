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
  void matrix_add(const Matrix& b);
  void matrix_sub(const Matrix& b);
  void hadamard(const Matrix& b);
  void matrix_mul_s(double s);
  void matrix_sub_s(double s);
  void add_vec(std::vector<double>& v, bool to_col);
  void apply(std::function<double(double)> f);
  void set(size_t row, size_t col, double val);
  double get(size_t row, size_t col);
  Matrix transpose() const;
};

double dot(const std::vector<double>& a, const std::vector<double>& b);

#endif