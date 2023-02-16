#include <iostream>
#include <vector>
#include <set>

void LineSplit(std::set<std::string> &all_paths, std::string &line) {
  size_t size = 0;
  size_t prev_size = 0;

  for (size_t i = 0; i < line.size(); ++i) {
    size++;

    if (line[i] == '/') {
      std::string sub = line.substr(0, prev_size);
      all_paths.insert(sub);
      prev_size = size;
    }

    if (i == line.size() - 1) {
      std::string sub = line.substr(0, prev_size);
      all_paths.insert(sub);
    }
  }
}

int main() {
  std::set<std::string> paths;
  std::string path;
  while (std::cin >> path) {
    if (path == "/") {
      continue;
    }
    LineSplit(paths, path);
  }

  for (const auto &s : paths) {
    if (s.empty() || s == " ") {
      continue;
    }
    std::cout << s << std::endl;
  }
  return 0;
}


