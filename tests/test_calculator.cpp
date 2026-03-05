#include <cassert>
#include <iostream>
#include <stdexcept>
#include "calculator.h"

void test_add() {
    Calculator calc;
    assert(calc.add(2, 3) == 5);
    assert(calc.add(-1, 1) == 0);
    assert(calc.add(0, 0) == 0);
    std::cout << "test_add passed" << std::endl;
}

void test_subtract() {
    Calculator calc;
    assert(calc.subtract(10, 4) == 6);
    assert(calc.subtract(0, 5) == -5);
    std::cout << "test_subtract passed" << std::endl;
}

void test_multiply() {
    Calculator calc;
    assert(calc.multiply(3, 4) == 12);
    assert(calc.multiply(-2, 5) == -10);
    assert(calc.multiply(0, 100) == 0);
    std::cout << "test_multiply passed" << std::endl;
}

void test_divide() {
    Calculator calc;
    assert(calc.divide(10.0, 2.0) == 5.0);
    assert(calc.divide(7.0, 2.0) == 3.5);
    std::cout << "test_divide passed" << std::endl;
}

void test_divide_by_zero() {
    Calculator calc;
    bool caught = false;
    try {
        calc.divide(1.0, 0.0);
    } catch (const std::invalid_argument&) {
        caught = true;
    }
    assert(caught);
    std::cout << "test_divide_by_zero passed" << std::endl;
}

int main() {
    test_add();
    test_subtract();
    test_multiply();
    test_divide();
    test_divide_by_zero();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
