#include <iostream>

int main() {
  int a;
  std::cin >> a;

  std::cout << "The next number for the number " << a << " is " << a + 1 << "." << std::endl;
  std::cout << "The previous number for the number " << a << " is " << a - 1 << "." << std::endl;
  return 0;
}