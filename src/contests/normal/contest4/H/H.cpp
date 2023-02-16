template <typename InIter, typename OutIter, typename Predicate>
OutIter RemoveCopyIf(InIter first, InIter last, OutIter out, Predicate f) {
  for ( ; first != last; ++first) {
    if (!f(*first)) {
      *out = *first;
      ++out;
    }
  }
  return out;
}