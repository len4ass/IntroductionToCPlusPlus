#include "../c.h"
#include <utility>

int main() {
  C c1;
  C c2 = C(std::move(c1));

  return 0;
}