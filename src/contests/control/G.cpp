#include <set>

void RemoveEvenElements(std::set<int64_t>& s) {
  erase_if(s, [](const int64_t& v){
    return v % 2 == 0;
  });
}