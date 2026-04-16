#include "quadratic_equation.h"
#include <iostream>
#include <cmath>
#include <sstream>

QuadraticEquation::QuadraticEquation(double a_, double b_, double c_)
    : a(a_), b(b_), c(c_) {}

QuadraticEquationException::QuadraticEquationException(const std::string& message, const QuadraticEquation& eq_)
    : std::invalid_argument(message), eq(eq_) {}

void QuadraticEquationException::print() const {
    std::cout << "Oshibka: " << what() << std::endl;
    std::cout << "Nedopustimoe uravnenie: a=" << eq.a << ", b=" << eq.b << ", c=" << eq.c << std::endl;
}

std::pair<double, double> solveQuadratic(const QuadraticEquation& eq) {
    double discriminant = eq.b * eq.b - 4 * eq.a * eq.c;
    if (discriminant < 0) {
        std::stringstream ss;
        ss << "Diskriminant menshe nulya: " << discriminant;
        throw QuadraticEquationException(ss.str(), eq);
    }
    double sqrtD = std::sqrt(discriminant);
    double x1 = (-eq.b + sqrtD) / (2 * eq.a);
    double x2 = (-eq.b - sqrtD) / (2 * eq.a);
    return std::make_pair(x1, x2);
}