#include <iostream>
#include <utility>
#include "quadratic_equation.h"

std::pair<double, double> solveQuadratic(const QuadraticEquation& eq);

int main() {
    std::cout << "=== Bez isklyucheniya ===" << std::endl;
    QuadraticEquation eq1(1, -3, 2);
    try {
        std::pair<double, double> roots = solveQuadratic(eq1);
        std::cout << "Korni: x1=" << roots.first << ", x2=" << roots.second << std::endl;
    } catch (const QuadraticEquationException& ex) {
        ex.print();
    }

    std::cout << "\n=== S isklyucheniem ===" << std::endl;
    QuadraticEquation eq2(1, 2, 3);
    try {
        std::pair<double, double> roots = solveQuadratic(eq2);
        std::cout << "Korni: x1=" << roots.first << ", x2=" << roots.second << std::endl;
    } catch (const QuadraticEquationException& ex) {
        ex.print();
    }

    return 0;
}