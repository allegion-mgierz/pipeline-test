#include "calculator.h"
#include <cmath>
#include <limits>
#include <stdexcept>

int Calculator::add(int a, int b) {
    return a + b;
}

int Calculator::subtract(int a, int b) {
    return a - b;
}

int Calculator::multiply(int a, int b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (std::abs(b) < std::numeric_limits<double>::epsilon()) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}
