#include "Toyota.h"

Toyota::Toyota() {
    CarName = new char[6];
    strcpy(CarName, "Dacia");
    CarName[5]       = '\0';
    fuel_capacity    = 80;
    fuel_consumption = 7.0;
    average_speed    = 55;
}

char* Toyota::GetName() const {
    return CarName;
}

float Toyota::GetFuelCapacity() const {
    return fuel_capacity;
}

float Toyota::GetFuelCosumption() const {
    return fuel_consumption;
}

int Toyota::GetSpeed() const {
    return average_speed;
}

void Toyota::SetWeather(Weather weather) {
    this->weather = weather;
    if (this->weather == Weather::Sunny)
        average_speed = 70;
    if (this->weather == Weather::Snow)
        average_speed = 45;
}
