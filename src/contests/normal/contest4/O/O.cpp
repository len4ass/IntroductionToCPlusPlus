#include <iostream>
#include <map>
#include <vector>

struct Star {
  std::string name;
  uint64_t age;
};

std::string FindStar(const std::vector<Star>& stars) {
  std::map<std::string, Star> m;
  for (const auto& star : stars) {
    auto& key = star.name;
    if (m.find(key) == m.end()) {
      m[key] = star;
    }
    auto& ref = m[key];
    if (ref.name == key) {
      if (star.age > ref.age) {
        ref.age = star.age;
      }
    }
  }
  std::vector<Star> new_stars(m.size());
  int32_t index = 0;
  for (auto& r : m) {
    new_stars[index] = r.second;
    index++;
  }
  std::sort(new_stars.begin(), new_stars.end(), [](const Star& x, const Star& y) {
    if (x.age == y.age) {
      return x.name < y.name;
    }

    return x.age < y.age;
  });
  Star median = new_stars[new_stars.size() / 2];
  for (auto& v : new_stars) {
    if (v.age == median.age) {
      return v.name;
    }
  }
  return median.name;
}