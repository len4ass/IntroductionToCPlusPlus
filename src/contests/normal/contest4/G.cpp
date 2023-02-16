template <typename It, typename Pred>
bool AnyOf(It first, It last, Pred f) {
  for (auto it = first; it != last; ++it) {
    if (f(*(it))) {
      return true;
    }
  }
  return false;
}