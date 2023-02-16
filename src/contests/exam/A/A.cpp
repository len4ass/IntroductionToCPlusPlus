#include <iostream>

class LoggerGuard {
private:
  std::ostream& o;
  std::string msg;
public:
  LoggerGuard(const std::string& message, std::ostream& out = std::cout):o(out), msg(message) {}

  ~LoggerGuard() {
    o << msg << '\n';
  }
};