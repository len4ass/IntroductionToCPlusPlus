#include <iostream>
#include <vector>

template<typename T>
class Matrix {
  std::vector<std::vector<T>> data;
  size_t rows;
  size_t columns;

public:
  Matrix(const std::vector<std::vector<T>>& vec): rows(vec.size()) {
    data = std::vector<std::vector<T>>(rows);
    std::vector<T> inner_vector;
    for (size_t i = 0; i < vec.size(); ++i) {
      if (i == 0) {
        columns = vec[i].size();
      }

      inner_vector.resize(vec[i].size());
      for (size_t j = 0; j < vec[i].size(); ++j) {
        inner_vector[j] = vec[i][j];
      }

      data[i] = inner_vector;
    }
  }

  std::pair<size_t, size_t> size() const {
    return {rows, columns};
  }

  Matrix& operator+=(const Matrix& rhs) {
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < columns; ++j) {
        data[i][j] += rhs.data[i][j];
      }
    }

    return *this;
  }

  Matrix operator+(const Matrix& rhs) const {
    Matrix tmp(data);
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < columns; ++j) {
        tmp.data[i][j] += rhs.data[i][j];
      }
    }

    return tmp;
  }

  template<typename U>
  Matrix& operator*=(const U& number) {
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < columns; ++j) {
        data[i][j] *= number;
      }
    }

    return *this;
  }

  Matrix& transpose() {
    size_t new_rows = columns, new_columns = rows;
    std::vector<std::vector<T>> new_data(new_rows);
    std::vector<T> inner_vector;
    for (size_t i = 0; i < new_rows; ++i) {
      inner_vector.resize(new_columns);
      for (size_t j = 0; j < new_columns; ++j) {
        inner_vector[j] = data[j][i];
      }

      new_data[i] = inner_vector;
    }

    data = new_data;
    rows = new_rows;
    columns = new_columns;
    return *this;
  }

  Matrix transposed() const {
    size_t new_rows = columns, new_columns = rows;
    std::vector<std::vector<T>> new_data(new_rows);
    std::vector<T> inner_vector;
    for (size_t i = 0; i < new_rows; ++i) {
      inner_vector.resize(new_columns);
      for (size_t j = 0; j < new_columns; ++j) {
        inner_vector[j] = data[j][i];
      }

      new_data[i] = inner_vector;
    }

    return {new_data};
  }

  template<typename U>
  Matrix operator*(const U& number) const {
    Matrix tmp(data);
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < columns; ++j) {
        tmp.data[i][j] *= number;
      }
    }

    return tmp;
  }

  friend std::ostream& operator<<(std::ostream& output, const Matrix& m) {
    for (size_t i = 0; i < m.rows; ++i) {
      for (size_t j = 0; j < m.columns; ++j) {
        if (j == m.columns - 1) {
          output << m.data[i][j];
        } else {
          output << m.data[i][j] << "\t";
        }
      }

      if (i != m.rows - 1) {
        output << std::endl;
      }
    }

    return output;
  }
};