#include <algorithm>

template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1, InIter2 first2, InIter2 last2, OutIter out) {
  bool iter_up = false;
  for ( ; first1 != last1; ++first1) {
    if (first2 == last2) {
      return std::copy(first1, last1, out);
    }

    if (iter_up) {
      first1--;
    }

    if (*first1 < *first2) {
      *out = *first1;
      ++out;
    } else {
      if (*first1 > *first2) {
        iter_up = true;
      }

      ++first2;
    }
  }
  return out;
}