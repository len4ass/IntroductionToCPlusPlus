Matrix(const Matrix& other): rows(other.rows), columns(other.columns) {
  data = new T*[rows];
  for (size_t i = 0; i < rows; ++i) {
    data[i] = new T[columns];
    for (size_t j = 0; j < columns; ++j) {
      data[i][j] = other.data[i][j];
    }
  }
}

Matrix& operator=(const Matrix& other) {
  if (this == &other) {
    return *this;
  }

  for (size_t i = 0; i < rows; ++i) {
    delete[] data[i];
  }
  delete[] data;

  rows = other.rows;
  columns = other.columns;
  data = new T*[rows];
  for (size_t i = 0; i < rows; ++i) {
    data[i] = new T[columns];
    for (size_t j = 0; j < columns; ++j) {
      data[i][j] = other.data[i][j];
    }
  }

  return *this;
}