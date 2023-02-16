#include <chrono>
#include <iostream>
#include <string>

class TimerGuard {
  std::string text;
  std::ostream* stream;
  std::chrono::time_point<std::chrono::high_resolution_clock> start_time =
      std::chrono::high_resolution_clock::now();

public:
  TimerGuard(std::string_view message = "", std::ostream& out = std::cout) {
    text = message;
    stream = &out;
  }

  ~TimerGuard() {
    std::chrono::duration<double> difference = std::chrono::high_resolution_clock::now()
                                               - start_time;
    (*stream) << text << " " << difference.count();
  }
};