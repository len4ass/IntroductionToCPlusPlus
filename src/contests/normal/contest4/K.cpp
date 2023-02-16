template <typename InIter, typename OutIter>
OutIter ReverseCopy(InIter first, InIter last, OutIter out) {
  for ( ; last != first;) {
    --last;
    *out = *last;
    ++out;
  }
  return out;
}