#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class Car {
public:
    std::string model;
    double fuelConsumption[3];
    int maxSpeed;
    int power;

    Car();
    Car(const std::string& model_, double fuel0, double fuel1, double fuel2, int maxSpeed_, int power_);
    Car(const Car& other);
    Car(Car&& other) noexcept;
    Car& operator=(const Car& other);
    Car& operator=(Car&& other) noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Car& car);
};

#endif