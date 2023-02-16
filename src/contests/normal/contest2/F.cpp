#include <iostream>
#include <vector>

int main() {
  int m, n;
  std::cin >> m >> n;
  std::vector<std::vector<int>> mega_vector;
  for (int i = 0; i < m; ++i) {
    std::vector<int> v;
    for (int j = 0; j < n; ++j) {
      int current;
      std::cin >> current;

      v.push_back(current);
    }

    mega_vector.push_back(v);
  }


  int k;
  std::cin >> k;

  for (int i = 0; i < m; ++i) {
    int current_sub = 0;
    int longest_sub = 0;
    for (int j = 0; j < n; ++j) {
      if (mega_vector[i][j] == 0) {
        current_sub++;

        if (current_sub > longest_sub) {
          longest_sub = current_sub;
        }
      } else {
        current_sub = 0;
      }
    }

    if (longest_sub >= k) {
      std::cout << i + 1 << std::endl;
      return 0;
    }
  }

  std::cout << 0 << std::endl;
  return 0;
}