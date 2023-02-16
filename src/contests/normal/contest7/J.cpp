#include <iostream>
#include <vector>

class Model {
public:
  std::vector<int> data;

  void save(std::ostream& out) const;
  void load(std::istream& in);
};

void Model::save(std::ostream& out) const {
  out.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(int));
}

void Model::load(std::istream& in) {
  in.seekg(0, std::ios::end);
  data.resize(in.tellg() / sizeof(int));
  in.seekg(0);
  in.read(reinterpret_cast<char*>(data.data()), data.size() * sizeof(int));
}


