#include "address.h"
#include <iostream>
#include <string>

int main() {
    std::string line;
    Address * address;
    while (getline(std::cin, line)) {
        Parse(line, address);
        Unify(address);
        std::cout << Format(*address) << "\n";
    }
}
