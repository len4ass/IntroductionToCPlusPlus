#include "c.h"

int main() {
  C* c1 = new C();
  delete c1;

  C* c2 = new C();
  delete c2;

  return 0;
}