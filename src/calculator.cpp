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

double Calculator::squareRoot(double x) {
    if (x < 0.0) {
        throw std::invalid_argument("Square root of negative number");
    }
    return std::sqrt(x);
}

double Calculator::power(double base, double exponent) {
    return std::pow(base, exponent);
}

double Calculator::logarithm(double x, double base) {
    if (x <= 0.0) {
        throw std::invalid_argument("Logarithm of non-positive number");
    }
    if (base <= 0.0 || std::abs(base - 1.0) < 1e-10) {
        throw std::invalid_argument("Invalid logarithm base");
    }
    return std::log(x) / std::log(base);
}

double Calculator::derivative(std::function<double(double)> f, double x, double h) {
    if (h <= 0.0) {
        throw std::invalid_argument("Step size h must be positive");
    }
    return (f(x + h) - f(x - h)) / (2.0 * h);
}
