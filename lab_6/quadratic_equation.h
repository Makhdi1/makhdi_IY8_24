#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H

#include <stdexcept>
#include <string>

class QuadraticEquation {
public:
    double a;
    double b;
    double c;

    QuadraticEquation(double a_, double b_, double c_);
};

class QuadraticEquationException : public std::invalid_argument {
public:
    QuadraticEquation eq;

    QuadraticEquationException(const std::string& message, const QuadraticEquation& eq_);
    void print() const;
};

#endif