#include <iostream>
#include <algorithm>
#include <vector>

template<typename It, typename OutputIt>
OutputIt SidewaysMerge(It first1, It last1, It first2, It last2, OutputIt out) {
  if (first1 == last1 && first2 == last2) {
    return out;
  } else if (first1 == last1) {
    return std::reverse_copy(first2, last2, out);
  } else if (first2 == last2) {
    return std::copy(first1, last1, out);
  }

  int32_t cnt = 0;
  for (; first1 != last1; ) {
    if (first2 == last2) {
      if (*first1 > *last2) {
        *out++ = *last2;
        return std::copy(first1, last1, out);
      } else {
        *out++ = *first1++;
        *out++ = *last2;
        return std::copy(first1, last1, out);
      }
    }

    if (*first1 > *--last2) {
      *out++ = *last2;
    } else {
      last2++;
      *out++ = *first1++;
    }

    cnt++;
  }

  return std::reverse_copy(first2, last2, out);
}