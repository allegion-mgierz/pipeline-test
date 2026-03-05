#pragma once

#include <functional>

class Calculator {
public:
    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    double divide(double a, double b);
    double squareRoot(double x);
    double power(double base, double exponent);
    double logarithm(double x, double base = 10.0);
    double derivative(std::function<double(double)> f, double x, double h = 1e-5);
};
