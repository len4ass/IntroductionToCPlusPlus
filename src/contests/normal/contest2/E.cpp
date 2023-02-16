#include <iostream>
#include <vector>

int main() {
  int m, n, mines;
  std::cin >> m >> n >> mines;
  std::vector<std::vector<char>> mega_vector;
  for (int i = 0; i < m; ++i) {
    std::vector<char> v;
    for (int j = 0; j < n; ++j) {
      v.push_back('n');
    }

    mega_vector.push_back(v);
  }

  int x, y;
  for (int i = 0; i < mines; i++) {
    std::cin >> x >> y;
    mega_vector[x - 1][y - 1] = 'y';
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (mega_vector[i][j] != 'y') {
        int count = 0;
        for (int row = i - 1; row <= i + 1; ++row) {
          for (int column = j - 1; column <= j + 1; ++column) {
            if (row >= 0 && row <= m - 1 && column >= 0 && column <= n - 1) {
              if (mega_vector[row][column] == 'y') {
                count++;
              }
            }
          }
        }

        if (j == n - 1) {
          std::cout << count << std::endl;
        } else {
          std::cout << count << " ";
        }
      } else {
        if (j == n - 1) {
          std::cout << "*" << std::endl;
        } else {
          std::cout << "*" << " ";
        }
      }
    }
  }

  return 0;
}