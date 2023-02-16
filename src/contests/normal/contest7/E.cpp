#include <map>
#include <stdexcept>
#include <optional>

template <typename Key1, typename Key2, typename Value>
class BiMap {
public:
  void Insert(const std::optional<Key1>& key1, const std::optional<Key2>& key2, const Value& value) {
    if (!key1.has_value() && !key2.has_value()) {
      throw std::invalid_argument("some text");
    }

    for (auto& v : m) {
      auto& p = v.first;
      if (p.first.has_value() && key1.has_value() && p.first.value() == key1.value()) {
        throw std::invalid_argument("some text");
      }

      if (p.second.has_value() && key2.has_value() && p.second.value() == key2.value()) {
        throw std::invalid_argument("some text");
      }
    }

    m[std::make_pair(key1, key2)] = value;
  }

  Value& GetByPrimaryKey(const Key1& key) {
    for (auto& i : m) {
      auto& p = i.first;
      if (p.first.has_value() && p.first.value() == key) {
        return i.second;
      }
    }

    throw std::out_of_range("some text");
  }
  const Value& GetByPrimaryKey(const Key1& key) const {
    for (const auto& i : m) {
      const auto& p = i.first;
      if (p.first.has_value() && p.first.value() == key) {
        return i.second;
      }
    }

    throw std::out_of_range("some text");
  }

  Value& GetBySecondaryKey(const Key2& key) {
    for (auto& i : m) {
      auto& p = i.first;
      if (p.second.has_value() && p.second.value() == key) {
        return i.second;
      }
    }

    throw std::out_of_range("some text");
  }
  const Value& GetBySecondaryKey(const Key2& key) const {
    for (const auto& i : m) {
      const auto& p = i.first;
      if (p.second.has_value() && p.second.value() == key) {
        return i.second;
      }
    }

    throw std::out_of_range("some text");
  }
private:
  std::map<std::pair<std::optional<Key1>, std::optional<Key2>>, Value> m;
};

