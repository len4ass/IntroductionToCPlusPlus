#include "some_long_stuff.h"

#include <iostream>
#include <chrono>

void SomeFunc() {
  {
    TimerGuard timer("FirstLongFunction elapsed: ", std::cerr);
    FirstLongFunction();
  }

  {
    TimerGuard timer("SecondLongFunction elapsed: ", std::cerr);
    SecondLongFunction();
  }

  {
    TimerGuard timer("ThirdLongFunction elapsed: ", std::cerr);
    ThirdLongFunction();
  }
}

int main() {
  SomeFunc();
  return 0;
}