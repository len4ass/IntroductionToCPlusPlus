#include <vector>
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> vec;
  int val;

  for (int i = 0; i < n; ++i) {
    std::vector<int> push;
    for (int j = 0; j < n; ++j) {
      std::cin >> val;
      push.push_back(val);
    }

    vec.push_back(push);
  }


  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        int i_jk = vec[vec[i][j]][k];
        int ij_k = vec[i][vec[j][k]];

        if (i_jk != ij_k) {
          std::cout << "NO" << std::endl;
          return 0;
        }
      }
    }
  }

  std::cout << "YES" << std::endl;
  return 0;
}