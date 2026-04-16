#include "car.h"

Car::Car() : model(""), maxSpeed(0), power(0) {
    fuelConsumption[0] = 0.0;
    fuelConsumption[1] = 0.0;
    fuelConsumption[2] = 0.0;
}

Car::Car(const std::string& model_, double fuel0, double fuel1, double fuel2, int maxSpeed_, int power_)
    : model(model_), maxSpeed(maxSpeed_), power(power_) {
    fuelConsumption[0] = fuel0;
    fuelConsumption[1] = fuel1;
    fuelConsumption[2] = fuel2;
}

Car::Car(const Car& other)
    : model(other.model), maxSpeed(other.maxSpeed), power(other.power) {
    fuelConsumption[0] = other.fuelConsumption[0];
    fuelConsumption[1] = other.fuelConsumption[1];
    fuelConsumption[2] = other.fuelConsumption[2];
}

Car::Car(Car&& other) noexcept
    : model(std::move(other.model)), maxSpeed(other.maxSpeed), power(other.power) {
    fuelConsumption[0] = other.fuelConsumption[0];
    fuelConsumption[1] = other.fuelConsumption[1];
    fuelConsumption[2] = other.fuelConsumption[2];
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        model = other.model;
        fuelConsumption[0] = other.fuelConsumption[0];
        fuelConsumption[1] = other.fuelConsumption[1];
        fuelConsumption[2] = other.fuelConsumption[2];
        maxSpeed = other.maxSpeed;
        power = other.power;
    }
    return *this;
}

Car& Car::operator=(Car&& other) noexcept {
    if (this != &other) {
        model = std::move(other.model);
        fuelConsumption[0] = other.fuelConsumption[0];
        fuelConsumption[1] = other.fuelConsumption[1];
        fuelConsumption[2] = other.fuelConsumption[2];
        maxSpeed = other.maxSpeed;
        power = other.power;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << "Model: " << car.model
       << ", Rashod (trassa/gorod/smesh): "
       << car.fuelConsumption[0] << "/"
       << car.fuelConsumption[1] << "/"
       << car.fuelConsumption[2]
       << ", Max skorost: " << car.maxSpeed
       << ", Moshnost: " << car.power;
    return os;
}