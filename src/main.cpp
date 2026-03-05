#include <iostream>
#include "calculator.h"

int main() {
    Calculator calc;

    std::cout << "Calculator Demo" << std::endl;
    std::cout << "3 + 4 = " << calc.add(3, 4) << std::endl;
    std::cout << "10 - 3 = " << calc.subtract(10, 3) << std::endl;
    std::cout << "6 * 7 = " << calc.multiply(6, 7) << std::endl;
    std::cout << "9 / 2 = " << calc.divide(9, 2) << std::endl;

    return 0;
}
