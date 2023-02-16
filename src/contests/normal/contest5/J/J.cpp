#include <deque>

template <typename T, typename Container = std::deque<T>>
class Queue {
  Container q;

public:
  Queue() = default;

  T front() const {
    return q.front();
  }

  T& front() {
    return q.front();
  }

  void pop() {
    q.pop_front();
  }

  void push(const T& element) {
    q.push_back(element);
  }

  size_t size() {
    return q.size();
  }

  bool empty() {
    return q.empty();
  }
  bool operator==(Queue& rhs) {
    return q == rhs.q;
  }
  bool operator!=(Queue& rhs) {
    return q != rhs.q;
  }
};


