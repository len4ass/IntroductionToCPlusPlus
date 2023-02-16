#include "some_long_stuff.h"

#include <iostream>
#include <chrono>

void SomeFunc() {
  auto start1 = std::chrono::high_resolution_clock::now();
  FirstLongFunction();
  std::chrono::duration<double> diff1 = std::chrono::high_resolution_clock::now() - start1;
  std::cerr << "FirstLongFunction elapsed: " << diff1.count() << "\n";
	
  auto start2 = std::chrono::high_resolution_clock::now();
  SecondLongFunction();
  std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2;
  std::cerr << "SecondLongFunction elapsed: " << diff2.count() << "\n";
	
  auto start3 = std::chrono::high_resolution_clock::now();
  ThirdLongFunction();
  std::chrono::duration<double> diff3 = std::chrono::high_resolution_clock::now() - start3;
  std::cerr << "ThirdLongFunction elapsed: " << diff3.count() << "\n";
}

int main() {
  SomeFunc();
  return 0;
}