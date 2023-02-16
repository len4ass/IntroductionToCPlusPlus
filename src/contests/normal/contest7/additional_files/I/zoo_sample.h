#include "animals.h"

#include <iostream>
#include <stdexcept>
#include <vector>

using Zoo = std::vector<Animal>;

Zoo CreateZoo() {
    Zoo zoo;
    std::string word;
    while (std::cin >> word) {
        if (word == "Tiger") {
            Tiger t;
            zoo.push_back(t);
        } else if (word == "Wolf") {
            Wolf w;
            zoo.push_back(w);
        } else if (word == "Fox") {
            Fox f;
            zoo.push_back(f);
        } else
            throw std::runtime_error("Unknown animal!");
    }
    return zoo;
}

void Process(const Zoo& zoo) {
    for (const auto& animal : zoo) {
        std::cout << animal.voice() << "\n";
    }
}
