#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::string> SplitString(const std::string& input, const char& delim) {
  std::vector<std::string> lines;
  size_t current_position = 0, previous_position = 0;
  while ((current_position = input.find(delim, previous_position)) != std::string::npos) {
    lines.push_back(input.substr(previous_position, current_position - previous_position));
    previous_position = current_position + 1;
  }

  lines.push_back(input.substr(previous_position));
  return lines;
}


int main() {
  std::vector<std::pair<std::pair<int32_t, bool>, std::vector<int32_t>>> contests;

  std::string buffer;
  std::vector<std::string> lines;
  while (std::getline(std::cin, buffer, '\n')) {
    if (buffer != "") {
      lines.push_back(buffer);
    }
  }

  for (auto& v : lines) {
    auto vs = SplitString(v, ' ');
    std::vector<int32_t> nums;
    int32_t contest_num = std::stoi(vs[0]);
    int32_t array_num = std::stoi(vs[1]);
    if (vs.size() == 2) {
      for (int i = 1; i <= array_num; ++i) {
        nums.push_back(i);
      }

      contests.emplace_back(std::make_pair(contest_num, true), nums);
    } else {
      auto fv = static_cast<int>(static_cast<u_char>(vs[2][0]));
      if (fv >= 65 && fv <= 90) {
        for (int32_t i = 65; i < 65 + array_num; ++i) {
          char m = static_cast<char>(i);
          std::string s(1, m);
          if (std::find(vs.begin() + 2, vs.end(), s) == vs.end()) {
            nums.push_back(i);
          }
        }

        contests.emplace_back(std::make_pair(contest_num, false), nums);
      } else {
        for (int32_t i = 1; i <= array_num; ++i) {
          auto m = std::to_string(i);
          if (std::find(vs.begin() + 2, vs.end(), m) == vs.end()) {
            nums.push_back(i);
          }
        }

        contests.emplace_back(std::make_pair(contest_num, true), nums);
      }
    }
  }

  for (const auto& v : contests) {
    auto& [contest, is_letter] = v.first;
    std::cout << contest;

    auto& vec = v.second;
    if (!is_letter) {
      for (auto val : vec) {
        std::cout << " " << static_cast<char>(val);
      }

      std::cout << std::endl;
    } else {
      for (auto val : vec) {
        std::cout << " " << val;
      }

      std::cout << std::endl;
    }
  }

  return 0;
}