#include <iostream>
#include <map>
#include <vector>

int main() {
  std::map<std::string, std::vector<int32_t>> results;
  int32_t amount, student_amount;
  std::cin >> amount;

  if (amount == 0) {
    return 0;
  }

  std::string student_name;
  int32_t student_result;

  for (int32_t i = 0; i < amount; ++i) {
    std::cin >> student_amount;
    for (int32_t j = 0; j < student_amount; ++j) {
      std::cin >> student_name >> student_result;
      auto &ref = results[student_name];
      if (ref.empty()) {
        ref = std::vector<int32_t>(amount);
      }

      ref[i] = student_result;
    }
  }

  for (const auto &user : results) {
    std::cout << user.first << "\t";
    auto &vec = user.second;
    for (size_t i = 0; i < vec.size(); ++i) {
      if (i == vec.size() - 1) {
        std::cout << vec[i] << std::endl;
        break;
      }

      std::cout << vec[i] << "\t";
    }
  }

  return 0;
}