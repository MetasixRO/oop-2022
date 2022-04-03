#include "Mercedes.h"

Mercedes::Mercedes() {
    CarName = new char[8];
    strcpy(CarName, "Mercedes");
    CarName[5]       = '\0';
    fuel_capacity    = 80.0;
    fuel_consumption = 8.5;
    average_speed    = 60;
}

char* Mercedes::GetName() const {
    return this->CarName;
}

float Mercedes::GetFuelCapacity() const {
    return this->fuel_capacity;
}

float Mercedes::GetFuelCosumption() const {
    return this->fuel_consumption;
}

int Mercedes::GetSpeed() const {
    return this->average_speed;
}

void Mercedes::SetWeather(Weather weather) {
    this->weather = weather;
    if (this->weather == Weather::Sunny)
        average_speed = 80;
    if (this->weather == Weather::Snow)
        average_speed = 40;
}
