#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> get_matrix(size_t n) {
  vector<vector<int>> mat(n);
  for (size_t i = 0; i < n; ++i) {
    vector<int> m(n);
    for (size_t j = 0; j < n; ++j) {
      if (i % 2 == 0) {
        m[j] = j % 2 == 0 ? 0 : 1;
      } else {
        m[j] = j % 2 == 1 ? 0 : 1;
      }
    }

    mat[i] = m;
  }

  return mat;
}