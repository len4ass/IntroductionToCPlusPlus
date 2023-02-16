#include <iostream>

template<typename Iterator, typename T, typename BinaryOp>
T Reduce(Iterator first, Iterator last, T init, BinaryOp op) {
  if (first == last) {
    return init;
  }

  for ( ; first != last ; ++first) {
    init = op(init, *first);
  }

  return init;
}