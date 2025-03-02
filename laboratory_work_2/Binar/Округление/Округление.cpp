#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double x = 3;

    // Использование стандартных функций
    std::cout << "round(3.5) = " << round(x) << std::endl;  // 4
    std::cout << "ceil(3.5) = " << ceil(x) << std::endl;    // 4
    std::cout << "floor(3.5) = " << floor(x) << std::endl;  // 3
    std::cout << "trunc(3.5) = " << trunc(x) << std::endl;  // 3

    // Использование функций из библиотеки cmath
    std::cout << "std::round(3.5) = " << std::round(x) << std::endl;  // 4
    std::cout << "std::ceil(3.5) = " << std::ceil(x) << std::endl;    // 4
    std::cout << "std::floor(3.5) = " << std::floor(x) << std::endl;  // 3
    std::cout << "std::trunc(3.5) = " << std::trunc(x) << std::endl;  // 3

    // Использование модификаторов потока
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "3.5 округленное = " << x << std::endl;  // 3.5

    return 0;
}
