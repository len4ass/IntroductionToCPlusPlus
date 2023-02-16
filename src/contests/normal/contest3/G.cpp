#include <iostream>
#include <vector>
#include <set>

int main() {
  int32_t word_amount;
  std::vector<std::string> words;
  std::string alphabet, str;

  std::cin >> alphabet >> word_amount;
  std::set<char> valid_alphabet;
  for (char c : alphabet) {
    valid_alphabet.insert(c);
  }

  for (int32_t i = 0; i < word_amount; ++i) {
    std::cin >> str;

    bool allow = true;
    for (const auto &c : str) {
      if (!valid_alphabet.contains(c)) {
        allow = false;
        break;
      }
    }

    if (allow) {
      words.push_back(str);
    }
  }

  for (const auto &word : words) {
    std::cout << word << std::endl;
  }

  return 0;
}