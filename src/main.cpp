#include <iostream>
#include "calculator.h"

int main() {
    Calculator calc;

    std::cout << "C++ Calculator Example" << std::endl;
    std::cout << "======================" << std::endl;

    std::cout << "3 + 4 = "  << calc.add(3, 4)      << std::endl;
    std::cout << "10 - 6 = " << calc.subtract(10, 6) << std::endl;
    std::cout << "5 * 7 = "  << calc.multiply(5, 7)  << std::endl;
    std::cout << "8 / 2 = "  << calc.divide(8, 2)    << std::endl;

    return 0;
}
