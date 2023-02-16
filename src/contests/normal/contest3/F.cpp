#include <iostream>
#include <map>
#include <vector>

int main() {
  int32_t witness_amount;
  std::cin >> witness_amount;

  std::string current_witness;
  std::vector<std::string> witnesses(witness_amount);
  for (int32_t i = 0; i < witness_amount; ++i) {
    std::cin >> current_witness;
    witnesses[i] = current_witness;
  }

  int32_t plate_amount;
  std::cin >> plate_amount;

  std::string current_plate;
  std::vector<std::string> plates(plate_amount);
  for (int32_t i = 0; i < plate_amount; ++i) {
    std::cin >> current_plate;
    plates[i] = current_plate;
  }

  int32_t max_found = 0;
  std::map<std::string, int32_t> m;
  for (auto &p : plates) {
    int32_t found = 0;

    for (auto &w : witnesses) {
      bool allow = true;
      for (auto &c : w) {
        if (p.find(c) == std::string::npos) {
          allow = false;
          break;
        }
      }

      if (allow) {
        found++;
      }
    }

    if (found > max_found) {
      max_found = found;
    }

    m[p] = found;
  }

  for (const auto &p : plates) {
    if (m[p] == max_found) {
      std::cout << p << std::endl;
    }
  }

  return 0;
}