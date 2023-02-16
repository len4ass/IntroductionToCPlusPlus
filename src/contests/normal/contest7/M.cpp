#include <map>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void Serialize(T pod, std::ostream& out);

void Serialize(const std::string& str, std::ostream& out);

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out);

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out);

template <typename T>
void Deserialize(std::istream& in, T& pod);

void Deserialize(std::istream& in, std::string& str);

template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data);

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data);

template <typename T>
void Serialize(T pod, std::ostream& out) {
  out.write(reinterpret_cast<const char*>(&pod), sizeof(T));
}

void Serialize(const std::string& str, std::ostream& out) {
  size_t sz = str.size();
  out.write(reinterpret_cast<const char*>(&sz), sizeof(size_t));
  out.write(reinterpret_cast<const char*>(str.data()), sz);
}

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out) {
  size_t sz = data.size();
  out.write(reinterpret_cast<const char*>(&sz), sizeof(size_t));
  for (const auto& item : data) {
    Serialize(item, out);
  }
}

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out) {
  size_t sz = data.size();
  out.write(reinterpret_cast<const char*>(&sz), sizeof(size_t));
  for (const auto& [k, v] : data) {
    Serialize(k, out);
    Serialize(v, out);
  }
}

template <typename T>
void Deserialize(std::istream& in, T& pod) {
  in.read(reinterpret_cast<char*>(&pod), sizeof(T));
}

void Deserialize(std::istream& in, std::string& str) {
  size_t sz;
  in.read(reinterpret_cast<char*>(&sz), sizeof(size_t));
  str.clear();
  str.resize(sz);
  if (sz > 0) {
    in.read(const_cast<char*>(str.data()), sz);
  }
}

template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data) {
  size_t sz;
  in.read(reinterpret_cast<char*>(&sz), sizeof(size_t));
  data.clear();
  data.reserve(sz);
  for (size_t i = 0; i < sz; ++i) {
    T v;
    Deserialize(in, v);
    data.push_back(v);
  }
}

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data) {
  size_t sz;
  in.read(reinterpret_cast<char*>(&sz), sizeof(size_t));
  data.clear();
  for (size_t i = 0; i < sz; ++i) {
    T1 k;
    Deserialize(in, k);
    T2 v;
    Deserialize(in, v);
    data[k] = v;
  }
}