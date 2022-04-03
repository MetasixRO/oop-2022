#include "Mazda.h"

Mazda::Mazda() {
    CarName = new char[5];
    strcpy(CarName, "Mazda");
    CarName[5]       = '\0';
    fuel_capacity    = 66;
    fuel_consumption = 6.5;
    average_speed    = 50;
}

char* Mazda::GetName() const {
    return CarName;
}

float Mazda::GetFuelCapacity() const {
    return fuel_capacity;
}

float Mazda::GetFuelCosumption() const {
    return fuel_consumption;
}

int Mazda::GetSpeed() const {
    return average_speed;
}

void Mazda::SetWeather(Weather weather) {
    this->weather = weather;
    if (this->weather == Weather::Sunny)
        average_speed = 65;
    if (this->weather == Weather::Snow)
        average_speed = 35;
}
