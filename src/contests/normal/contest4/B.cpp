#include <iostream>
#include <queue>

void ClearPriorityQueue(std::priority_queue<int32_t>& priority_queue) {
  std::priority_queue<int32_t> empty_priority_queue;
  std::swap(priority_queue, empty_priority_queue);
}

void AddValueToPriorityQueue(std::priority_queue<int32_t>& priority_queue, int32_t& value) {
  priority_queue.push(value);
}

void ExtractMaxValue(std::priority_queue<int32_t>& priority_queue) {
  if (priority_queue.empty()) {
    std::cout << "CANNOT" << std::endl;
    return;
  }

  std::cout << priority_queue.top() << std::endl;
  priority_queue.pop();
}

int main() {
  std::priority_queue<int32_t> pq;
  std::string command;
  int32_t optional_input;

  while (std::cin >> command) {
    if (command == "CLEAR") {
      ClearPriorityQueue(pq);
      continue;
    }

    if (command == "ADD") {
      std::cin >> optional_input;
      AddValueToPriorityQueue(pq, optional_input);
      continue;
    }

    if (command == "EXTRACT") {
      ExtractMaxValue(pq);
      continue;
    }
  }

  return 0;
}