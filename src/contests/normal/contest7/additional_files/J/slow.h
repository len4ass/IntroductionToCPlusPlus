#include <iostream>
#include <vector>

class Model {
public:
    std::vector<int> data;

    void save(std::ostream& out) const;
    void load(std::istream& in);
};

void Model::save(std::ostream& out) const {
    out << data.size();
    for (auto elem : data)
        out << " " << elem;
}

void Model::load(std::istream& in) {
    size_t sz;
    in >> sz;
    data.resize(sz);
    for (size_t i = 0; i != sz; ++i)
        in >> data[i];
}
