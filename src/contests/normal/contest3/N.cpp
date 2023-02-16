#include <iostream>
#include <list>
#include <vector>

int main() {
  int32_t amount;
  std::cin >> amount;

  std::list<int32_t> v(0);
  std::vector<std::list<int32_t>::iterator> iter_lookup(100001, v.end());

  int32_t player, ptr_player;
  for (int32_t i = 0; i < amount; i++) {
    std::cin >> player >> ptr_player;

    if (iter_lookup[ptr_player] == v.end()) {
      v.push_front(player);
      iter_lookup[player] = v.begin();
    } else {
      auto cur_it = iter_lookup[ptr_player];
      ++cur_it;
      auto it = v.insert(cur_it, player);
      iter_lookup[player] = it;
    }
  }

  for (const auto &v_a : v) {
    std::cout << v_a << std::endl;
  }
}

