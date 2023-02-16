#include "model.h"

#include <iostream>
#include <sstream>

int main() {
    // заклинание для ускорения потокового ввода-вывода
    std::ios::sync_with_stdio(false);

    Model m1;

    // как-то заполняем m1.data случайными числами

    std::stringstream ss;  // записываем данные не в файл, а просто в память (в строку)
    m1.save(ss);

    Model m2;
    m2.load(ss);

    if (m1.data != m2.data)
        std::cout << "Models differ\n";
}
