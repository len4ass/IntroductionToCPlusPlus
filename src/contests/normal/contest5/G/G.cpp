#include "../c.h"
#include <iostream>
#include <utility>
#include <vector>

int main() {
  int32_t n;
  std::cin >> n;

  std::vector<C*> obj_vec(n);
  for (int32_t i = 0; i < n; ++i) {
    obj_vec[i] = new C();
  }

  for (int32_t i = 0; i < n; ++i) {
    delete obj_vec[i];
  }

  return 0;
}