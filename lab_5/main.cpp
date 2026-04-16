#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include "car.h"

int main() {
    std::vector<Car> cars;
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Ne udalos otkrit input.txt" << std::endl;
        return 1;
    }

    std::string model;
    double f0, f1, f2;
    int maxSpeed, power;
    while (inputFile >> model >> f0 >> f1 >> f2 >> maxSpeed >> power) {
        cars.push_back(Car(model, f0, f1, f2, maxSpeed, power));
    }
    inputFile.close();

    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Ne udalos sozdat output.txt" << std::endl;
        return 1;
    }

    outputFile << "Ishodniy konteiner (vector):" << std::endl;
    for (const auto& car : cars) {
        outputFile << car << std::endl;
    }

    std::sort(cars.begin(), cars.end(),
              [](const Car& a, const Car& b) {
                  return a.model < b.model;
              });

    outputFile << "\nKonteiner posle sortirovki po modeli:" << std::endl;
    for (const auto& car : cars) {
        outputFile << car << std::endl;
    }

    std::deque<Car> carsDeque;
    std::copy(cars.begin(), cars.end(), std::back_inserter(carsDeque));

    outputFile << "\nSkopirovanniy konteiner (deque):" << std::endl;
    for (const auto& car : carsDeque) {
        outputFile << car << std::endl;
    }

    outputFile.close();

    std::cout << "Programma zavershena. Rezultat v output.txt" << std::endl;
    return 0;
}