#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func, int retryCount, int sleepTime, bool throwLast) {
  Result r;
  for (int32_t i = 0; i <= retryCount; ++i) {
    try {
      r = func();
      break;
    } catch (Exception& v) {
      if (i == retryCount) {
        if (throwLast) {
          throw v;
        }

        return {};
      }

      Sleep(sleepTime);
    }
  }

  return r;
}