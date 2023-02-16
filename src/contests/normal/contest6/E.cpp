#include <iostream>
#include <vector>

template<typename T>
class Matrix {
  std::vector<T> data;
  size_t rows;
  size_t columns;

public:
  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;

  iterator begin() {
    return data.begin();
  }

  const_iterator begin() const {
    return data.begin();
  }

  iterator end() {
    return data.end();
  }

  const_iterator end() const {
    return data.end();
  }

  Matrix(const std::vector<std::vector<T>>& vec) {
    rows = vec.size();
    columns = vec[0].size();
    data = std::vector<T>(rows * columns);
    for (size_t i = 0; i < rows; ++i) {
      if (i == 0) {
        columns = vec[i].size();
      }

      for (size_t j = 0; j < vec[i].size(); ++j) {
        data[i * vec[i].size() + j] = vec[i][j];
      }
    }
  }

  Matrix(const std::vector<T>& vec, size_t r, size_t c) {
    rows = r;
    columns = c;
    data = std::vector<T>(rows * columns);
    for (size_t i = 0; i < rows * columns; ++i) {
      data[i] = vec[i];
    }
  }

  T operator()(size_t i, size_t j) const {
    return data[i * columns + j];
  }

  T& operator()(size_t i, size_t j) {
    return data[i * columns + j];
  }

  std::pair<size_t, size_t> size() const {
    return {rows, columns};
  }

  Matrix& operator+=(const Matrix& rhs) {
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < columns; ++j) {
        this->operator()(i, j) += rhs(i, j);
      }
    }

    return *this;
  }

  Matrix operator+(const Matrix& rhs) const {
    Matrix tmp(data, rows, columns);
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < columns; ++j) {
        tmp(i, j) += rhs(i, j);
      }
    }

    return tmp;
  }

  template<typename U>
  Matrix& operator*=(const U& number) {
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < columns; ++j) {
        this->operator()(i, j) *= number;
      }
    }

    return *this;
  }

  template<typename U>
  Matrix operator*(const U& number) const {
    Matrix tmp(data, rows, columns);
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < columns; ++j) {
        tmp(i, j) *= number;
      }
    }

    return tmp;
  }

  Matrix& operator*=(const Matrix& other) {
    assert(columns == other.rows);
    size_t new_rows = rows, new_columns = other.columns;
    std::vector<T> new_data(new_rows * new_columns);
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < new_columns; ++j) {
        for (size_t k = 0; k < other.rows; ++k) {
          new_data[i * new_columns + j] += this->operator()(i, k) * other(k, j);
        }
      }
    }

    data = new_data;
    rows = new_rows;
    columns = new_columns;
    return *this;
  }

  Matrix operator*(const Matrix& other) const {
    assert(columns == other.rows);
    size_t new_rows = rows, new_columns = other.columns;
    std::vector<T> new_data(new_rows * new_columns);
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < new_columns; ++j) {
        for (size_t k = 0; k < other.rows; ++k) {
          new_data[i * new_columns + j] += this->operator()(i, k) * other(k, j);
        }
      }
    }

    return {new_data, new_rows, new_columns};
  }

  Matrix& transpose() {
    size_t new_rows = columns, new_columns = rows;
    std::vector<T> new_data(new_rows * new_columns);
    for (size_t i = 0; i < new_rows; ++i) {
      for (size_t j = 0; j < new_columns; ++j) {
        new_data[i * new_columns + j] = this->operator()(j, i);
      }
    }

    data = new_data;
    rows = new_rows;
    columns = new_columns;
    return *this;
  }

  Matrix transposed() const {
    size_t new_rows = columns, new_columns = rows;
    std::vector<T> new_data(new_rows * new_columns);
    for (size_t i = 0; i < new_rows; ++i) {
      for (size_t j = 0; j < new_columns; ++j) {
        new_data[i * new_columns + j] = this->operator()(j, i);
      }
    }

    return {new_data, new_rows, new_columns};
  }
  friend std::ostream& operator<<(std::ostream& output, const Matrix& m) {
    for (size_t i = 0; i < m.rows; ++i) {
      for (size_t j = 0; j < m.columns; ++j) {
        if (j == m.columns - 1) {
          output << m.data[i * m.columns + j];
        } else {
          output << m.data[i * m.columns + j] << "\t";
        }
      }

      if (i != m.rows - 1) {
        output << std::endl;
      }
    }

    return output;
  }
};