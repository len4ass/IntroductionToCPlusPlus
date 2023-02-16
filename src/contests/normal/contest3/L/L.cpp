#include <iostream>
#include <vector>
#include <map>

int32_t Scalar(const std::vector<int32_t> &lhs, const std::vector<int32_t> &rhs) {
  int32_t sum = 0;
  for (size_t i = 0; i < lhs.size(); ++i) {
    sum += (lhs[i] * rhs[i]);
  }

  return sum;
}

int32_t BestSum(std::vector<int32_t> &c,
                std::map<std::string, std::pair<std::vector<int32_t>, int32_t>> &m) {
  int32_t bsum = std::numeric_limits<int32_t>::min();

  auto s = (*m.begin());
  for (const auto &item : m) {
    int32_t sc = Scalar(c, item.second.first);
    if (sc > bsum) {
      bsum = sc;
    }
  }

  return bsum;
}

bool Sort(std::pair<std::string, int32_t> &lhs, std::pair<std::string, int32_t> &rhs) {
  return lhs.second < rhs.second;
}

int main() {
  std::map<std::string, std::pair<std::vector<int32_t>, int32_t>> m;
  int32_t amount, vec_size;
  std::cin >> amount >> vec_size;

  std::string word;
  int32_t coordinate;

  std::pair<std::string, std::vector<int32_t>> first_word;
  for (int32_t i = 0; i < amount; ++i) {
    std::cin >> word;
    std::vector<int32_t> vc(vec_size);

    for (int32_t j = 0; j < vec_size; ++j) {
      std::cin >> coordinate;
      vc[j] = coordinate;
    }

    if (i == 0) {
      first_word = std::make_pair(word, vc);
      continue;
    }

    m[word] = std::make_pair(vc, i);
  }

  int32_t best_sum = BestSum(first_word.second, m);
  std::vector<std::pair<std::string, int32_t>> best_words;

  auto iter = m.begin();
  for (iter = m.begin(); iter != m.end(); iter++) {
    auto p = *iter;
    int32_t sum = Scalar(p.second.first, first_word.second);
    if (sum == best_sum) {
      best_words.emplace_back(p.first, p.second.second);
    }
  }

  std::sort(best_words.begin(), best_words.end(), &Sort);
  for (const auto &s : best_words) {
    std::cout << s.first << std::endl;
  }

  return 0;
}