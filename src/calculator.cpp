#include "calculator.h"
#include <cmath>
#include <limits>
#include <stdexcept>

double Calculator::add(double a, double b) const {
    return a + b;
}

double Calculator::subtract(double a, double b) const {
    return a - b;
}

double Calculator::multiply(double a, double b) const {
    return a * b;
}

double Calculator::divide(double a, double b) const {
    if (std::abs(b) < std::numeric_limits<double>::epsilon()) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}
