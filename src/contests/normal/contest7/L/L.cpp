#include "writer.h"
#include <memory>
#include <cstring>

class BufferedWriter : public Writer {
  size_t buf_sz;
  std::unique_ptr<char[]> buf;
  size_t pos = 0;
public:
  BufferedWriter(size_t sz) : buf_sz(sz), buf(new char[sz]) {}

  void Write(const char* data, size_t len) override {
    size_t processed_bytes = 0;
    while (processed_bytes != len) {
      size_t free_space = buf_sz - pos;
      size_t size_to_write = (len - processed_bytes) > free_space
                                 ? free_space
                                 : (len - processed_bytes);
      std::memcpy(reinterpret_cast<void*>(&buf.get()[pos]),
                  data + processed_bytes,
                  size_to_write);
      pos += size_to_write;

      if (pos == buf_sz) {
        Writer::Write(buf.get(), pos);
        pos = 0;
      }
      processed_bytes += size_to_write;
    }
  }

  ~BufferedWriter() {
    if (pos > 0) {
      Writer::Write(buf.get(), pos);
    }
  }
};