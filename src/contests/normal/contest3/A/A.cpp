#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>

int32_t FindMaxValue(const std::map<char, int32_t> &map) {
  int32_t max = 0;

  for (auto v : map) {
    if (v.second > max) {
      max = v.second;
    }
  }

  return max;
}

// Кринж задача
void PrintKeys(const std::map<char, int32_t> &map) {
  for (const auto key : map) {
    std::cout << key.first;
  }

  std::cout << std::endl;
}

void SmartPrint(std::map<char, int32_t> &map) {
  size_t columns = map.size();
  int32_t rows = FindMaxValue(map);

  std::vector<std::vector<char>> g_vec;
  for (int32_t i = 0; i <= rows; ++i) {
    if (i == rows) {
      std::vector<char> inner_vec;
      for (std::pair<char, int32_t> k : map) {
        inner_vec.push_back(k.first);
      }

      g_vec.push_back(inner_vec);
      continue;
    }

    std::vector<char> inner_vec(columns);
    for (size_t j = 0; j < columns; ++j) {
      inner_vec[j] = ' ';
    }

    g_vec.push_back(inner_vec);
  }

  for (size_t i = 0; i < columns; ++i) {
    auto key = g_vec[rows][i];
    auto p_size = map[key];
    for (int32_t j = rows - 1; j > rows - 1 - p_size; --j) {
      g_vec[j][i] = '#';
    }
  }

  for (int32_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < columns; ++j) {
      if (j == columns - 1) {
        std::cout << g_vec[i][j] << std::endl;
        continue;
      }

      std::cout << g_vec[i][j];
    }
  }

  PrintKeys(map);
}

int main() {
  std::map<char, int32_t> m;
  std::ifstream file("input.txt");
  std::stringstream buffer;
  buffer << file.rdbuf();

  std::string content = buffer.str();
  for (char c : content) {
    if (c == ' ' || c == '\n') {
      continue;
    }

    if (m.find(c) == m.end()) {
      m.insert(std::pair<char, int32_t>(c, 1));
      continue;
    }

    m[c] = m[c] + 1;
  }

  SmartPrint(m);
  return 0;
}