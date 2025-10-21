#include <iostream>
#include <vector>
#include <iomanip>

#include "matrix.h"

Matrix::Matrix()
  : m_rows{0}
  , m_columns{0}
  , m_data{}
{
}

// Constructor does not use initializer list for easy validity check of arguments

Matrix::Matrix(size_t rows, size_t columns)
  : m_rows{validateSize(rows)}
  , m_columns{validateSize(columns)}
  , m_data{std::vector<std::vector<double>>(m_rows, std::vector<double>(m_columns, 0.0))}
{
}

Matrix::Matrix(const std::vector<std::vector<double>>& data)
  : m_rows(validateSize(data.size()))
  , m_columns(validateSize(data[0].size()))
  , m_data(data)
{
}

size_t Matrix::validateSize(size_t size)
{
  if (size <= 0) throw std::invalid_argument("Invalid input, matrix dimensions have to be positive!");
  return size;
}

void Matrix::print() const
{
  for (auto& row : m_data)
  {
    for (auto& n : row)
    {
      std::cout << std::setw(2);
      std::cout << n << " ";
    }
    std::cout << "\n";
  }
}

size_t Matrix::get_rows() const {return m_rows;}
size_t Matrix::get_columns() const {return m_columns;}

void Matrix::print_dim() const
{
  std::cout << "Dimensions: " << m_rows << " * " << m_columns << "\n";
}

std::vector<double> Matrix::get_col(int i) const
{
  std::vector<double> col;
  col.reserve(m_data[0].size());
  for (auto row : m_data)
  {
    col.push_back(row[i]);
  }
  return col;
}

double dot(const std::vector<double>& a, const std::vector<double>& b)
{
  double result{};
  if (a.size() != b.size()) throw std::invalid_argument("Invalid dimensions for dot product!");
  for (size_t i{}; i < a.size(); ++i)
  {
    result += a[i] * b[i];
  }
  return result;
}

Matrix Matrix::matrix_mul(const Matrix& b) const
{
  Matrix result(m_data.size(), b.m_data[0].size());
  if(!(get_columns() == b.get_rows())) throw std::invalid_argument("Matrices cannot be multiplied, invalid dimensions!");
  for (size_t i{}; i < result.m_data.size(); ++i) // row
  {
    for (size_t j{}; j < result.m_data[0].size(); ++j) // column
    {
      result.m_data[i][j] = dot(m_data[i], b.get_col(j));
    }
  }
  return result;
}

Matrix Matrix::matrix_add(const Matrix& b) const
{
  size_t rows = get_rows();
  size_t cols = get_columns();
  if (rows != b.m_data.size() || cols != b.m_data[0].size()) throw std::invalid_argument("Matrices must have the same dimensions");
  Matrix result(rows, cols);
  for (size_t i{}; i < rows; ++i)
  {
    for (size_t j{}; j < cols; ++j)
    {
      result.m_data[i][j] = m_data[i][j] + b.m_data[i][j];
    }
  }
  return result;
}

Matrix Matrix::matrix_sub(const Matrix& b) const
{
  size_t rows = get_rows();
  size_t cols = get_columns();
  if (rows != b.m_data.size() || cols != b.m_data[0].size()) throw std::invalid_argument("Matrices must have the same dimensions");
  Matrix result(rows, cols);
  for (size_t i{}; i < rows; ++i)
  {
    for (size_t j{}; j < cols; ++j)
    {
      result.m_data[i][j] = m_data[i][j] - b.m_data[i][j];
    }
  }
  return result;
}

Matrix Matrix::matrix_mul_s(double s) const
{
  size_t rows = get_rows();
  size_t cols = get_columns();
  Matrix result(rows, cols);
  for (size_t i{}; i < rows; ++i)
  {
    for (size_t j{}; j < cols; ++j)
    {
      result.m_data[i][j] = s * m_data[i][j];
    }
  }
  return result;
}

Matrix Matrix::matrix_sub_s(double s) const
{
  size_t rows = get_rows();
  size_t cols = get_columns();
  Matrix result(rows, cols);

  for (size_t i{}; i < rows; ++i)
  {
    for (size_t j{}; j < cols; ++j)
    {
      result.m_data[i][j] = m_data[i][j] - s;
    }
  }
  return result;
}

Matrix Matrix::transpose() const
{
  size_t rows = get_rows();
  size_t cols = get_columns();
  Matrix result(cols, rows);

  for (size_t i{}; i < rows; ++i)
  {
    for (size_t j{}; j < cols; ++j)
    {
      result.m_data[j][i] = m_data[i][j];
    }
  }
  return result;
}

Matrix Matrix::hadamard(const Matrix& b) const
{
  size_t rows = get_rows();
  size_t cols = get_columns();

  if (rows != b.get_rows() || cols != b.get_columns()) throw std::invalid_argument("Matrices must have the same dimensions");

  Matrix result(rows, cols);

  for (size_t i{}; i < rows; ++i)
  {
    for (size_t j{}; j < cols; ++j)
    {
      result.m_data[i][j] = m_data[i][j] * b.m_data[i][j];
    }
  }
  return result;
}

Matrix Matrix::add_vec(std::vector<double>& v, bool to_col) const
{
  size_t rows = get_rows();
  size_t cols = get_columns();

  if ((to_col && rows != v.size()) || (!to_col && cols != v.size()))
    throw std::invalid_argument("Dimensions don't match for vector addition");

  Matrix result(rows, cols);

  for (size_t i{}; i < rows; ++i)
  {
    for (size_t j{}; j < cols; ++j)
    {
      if (to_col) result.m_data[i][j] = m_data[i][j] + v[i];
      else result.m_data[i][j] = m_data[i][j] + v[j];
    }
  }
  return result;
}

Matrix Matrix::apply(std::function<double(double)> f) const
{
  size_t rows = get_rows();
  size_t cols = get_columns();
  Matrix result(rows, cols);

  for (size_t i{}; i < rows; ++i)
  {
    for (size_t j{}; j < cols; ++j)
    {
      result.m_data[i][j] = f(m_data[i][j]);
    }
  }
  return result;
}

