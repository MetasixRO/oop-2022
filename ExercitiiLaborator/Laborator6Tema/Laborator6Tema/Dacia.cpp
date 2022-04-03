#include "Dacia.h"

Dacia::Dacia() {
    CarName = new char[6];
    strcpy(CarName, "Dacia");
    CarName[5] = '\0';
    fuel_capacity = 45.5;
    fuel_consumption = 5.5;
    average_speed    = 50;
}

char* Dacia::GetName() const {
    return CarName;
}

float Dacia::GetFuelCapacity() const {
    return fuel_capacity;
}

float Dacia::GetFuelCosumption() const {
    return fuel_consumption;
}

int Dacia::GetSpeed() const {
    return average_speed;
}

void Dacia::SetWeather(Weather weather) {
    this->weather = weather;
    if (this->weather == Weather::Sunny)
        average_speed = 60;
    if (this->weather == Weather::Snow)
        average_speed = 30;
}
