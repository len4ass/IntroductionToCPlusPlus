#include <iostream>
#include <unordered_set>

bool Exists(const std::unordered_set<std::string> &set, const std::string &val) {
  return set.contains(val);
}

void Add(std::unordered_set<std::string> &set, std::string &val) {
  if (set.contains(val)) {
    return;
  }

  set.insert(val);
}

void Remove(std::unordered_set<std::string> &set, std::string &val) {
  if (!set.contains(val)) {
    return;
  }

  set.erase(val);
}

void Switch(std::unordered_set<std::string> &set, std::string &operation, std::string &val) {
  if (operation == "+") {
    Add(set, val);
  } else if (operation == "-") {
    Remove(set, val);
  } else if (operation == "?") {
    if (Exists(set, val)) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
}

int main() {
  std::unordered_set<std::string> s;
  std::string operation, val;

  while (std::cin >> operation) {
    if (operation == "#") {
      break;
    }

    std::cin >> val;
    if (val == "#") {
      break;
    }

    Switch(s, operation, val);
  }
  return 0;
}