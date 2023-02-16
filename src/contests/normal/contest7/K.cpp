#include <cstddef>
#include <iostream>
#include <exception>

class RangeError : public std::out_of_range {
public:
  explicit RangeError(const std::string& message) : std::out_of_range(message) {}
};

size_t CountValues(const char* data, size_t size) {
  size_t i = size > sizeof(size_t)
                 ? *reinterpret_cast<size_t*>(&const_cast<char*>(data)[0]) + sizeof(size_t)
                 : 0;
  size_t data_count = i > 0 ? 1 : 0;
  while (i < size) {
    data_count++;
    i += *reinterpret_cast<size_t*>(&const_cast<char*>(data)[i]) + sizeof(size_t);
  }

  if (i > size) {
    throw RangeError("hello");
  }
  return data_count;
}