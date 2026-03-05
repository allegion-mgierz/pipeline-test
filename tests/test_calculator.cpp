#include <cassert>
#include <cmath>
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

void test_square_root() {
    Calculator calc;
    assert(std::abs(calc.squareRoot(9.0) - 3.0) < 1e-9);
    assert(std::abs(calc.squareRoot(2.0) - std::sqrt(2.0)) < 1e-9);
    assert(std::abs(calc.squareRoot(0.0) - 0.0) < 1e-9);
    bool caught = false;
    try {
        calc.squareRoot(-1.0);
    } catch (const std::invalid_argument&) {
        caught = true;
    }
    assert(caught);
    std::cout << "test_square_root passed" << std::endl;
}

void test_power() {
    Calculator calc;
    assert(std::abs(calc.power(2.0, 10.0) - 1024.0) < 1e-9);
    assert(std::abs(calc.power(5.0, 0.0) - 1.0) < 1e-9);
    assert(std::abs(calc.power(9.0, 0.5) - 3.0) < 1e-9);
    assert(std::abs(calc.power(2.0, -1.0) - 0.5) < 1e-9);
    std::cout << "test_power passed" << std::endl;
}

void test_logarithm() {
    Calculator calc;
    assert(std::abs(calc.logarithm(100.0, 10.0) - 2.0) < 1e-9);
    assert(std::abs(calc.logarithm(8.0, 2.0) - 3.0) < 1e-9);
    assert(std::abs(calc.logarithm(std::exp(1.0), std::exp(1.0)) - 1.0) < 1e-9);
    bool caught_nonpositive = false;
    try {
        calc.logarithm(-1.0);
    } catch (const std::invalid_argument&) {
        caught_nonpositive = true;
    }
    assert(caught_nonpositive);
    bool caught_invalid_base = false;
    try {
        calc.logarithm(10.0, 1.0);
    } catch (const std::invalid_argument&) {
        caught_invalid_base = true;
    }
    assert(caught_invalid_base);
    std::cout << "test_logarithm passed" << std::endl;
}

void test_derivative() {
    Calculator calc;
    // Derivative of x^2 at x=3 should be 6
    auto square = [](double x) { return x * x; };
    assert(std::abs(calc.derivative(square, 3.0) - 6.0) < 1e-4);

    // Derivative of sin(x) at x=0 should be 1
    auto sineFunc = [](double x) { return std::sin(x); };
    assert(std::abs(calc.derivative(sineFunc, 0.0) - 1.0) < 1e-4);

    // Derivative of constant function should be 0
    auto constant = [](double x) { (void)x; return 5.0; };
    assert(std::abs(calc.derivative(constant, 2.0)) < 1e-4);

    bool caught = false;
    try {
        calc.derivative(square, 1.0, -1e-5);
    } catch (const std::invalid_argument&) {
        caught = true;
    }
    assert(caught);
    std::cout << "test_derivative passed" << std::endl;
}

int main() {
    test_add();
    test_subtract();
    test_multiply();
    test_divide();
    test_divide_by_zero();
    test_square_root();
    test_power();
    test_logarithm();
    test_derivative();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
