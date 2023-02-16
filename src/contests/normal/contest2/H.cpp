#include <vector>

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
  if (matrix.size() == 0) {
    std::vector<std::vector<int>> v(0);
    return v;
  }

  int m, n;
  m = matrix[0].size();
  n = matrix.size();
  std::vector<std::vector<int>> result;
  for (int i = 0; i < m; ++i) {
    std::vector<int> row;
    for (int j = 0; j < n; j++) {
      row.push_back(0);
    }
    result.push_back(row);
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; j++) {
      result[i][j] = matrix[j][i];
    }
  }

  return result;
}