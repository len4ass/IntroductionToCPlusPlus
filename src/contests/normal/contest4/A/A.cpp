#include <iostream>
#include <queue>

void PushValue(std::queue<int32_t>& queue, int32_t& value) {
  queue.push(value);
  std::cout << "ok" << std::endl;
}

void PopValue(std::queue<int32_t>& queue) {
  if (queue.empty()) {
    std::cout << "error" << std::endl;
    return;
  }

  std::cout << queue.front() << std::endl;
  queue.pop();
}

void GetFrontValue(std::queue<int32_t>& queue) {
  if (queue.empty()) {
    std::cout << "error" << std::endl;
    return;
  }

  std::cout << queue.front() << std::endl;
}

void GetSize(std::queue<int32_t>& queue) {
  std::cout << queue.size() << std::endl;
}

void ClearValues(std::queue<int32_t>& queue) {
  std::queue<int32_t> empty_queue;
  std::swap(queue, empty_queue);
  std::cout << "ok" << std::endl;
}

int main() {
  std::queue<int32_t> q;
  std::string command;
  int32_t optional_input;

  while (std::cin >> command) {
    if (command == "exit") {
      std::cout << "bye" << std::endl;
      break;
    }

    if (command == "push") {
      std::cin >> optional_input;
      PushValue(q, optional_input);
      continue;
    }

    if (command == "pop") {
      PopValue(q);
      continue;
    }

    if (command == "front") {
      GetFrontValue(q);
      continue;
    }

    if (command == "size") {
      GetSize(q);
    }

    if (command == "clear") {
      ClearValues(q);
    }
  }

  return 0;
}