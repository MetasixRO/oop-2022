#include "Ford.h"
Ford::Ford() {
    CarName = new char[5];
    strcpy(CarName, "Ford");
    CarName[4]       = '\0';
    fuel_capacity    = 65;
    fuel_consumption = 7.5;
    average_speed    = 60;
}

char* Ford::GetName() const {
    return CarName;
}

float Ford::GetFuelCapacity() const {
    return fuel_capacity;
}

float Ford::GetFuelCosumption() const {
    return fuel_consumption;
}

int Ford::GetSpeed() const {
    return average_speed;
}

void Ford::SetWeather(Weather weather) {
    this->weather = weather;
    if (this->weather == Weather::Sunny)
        average_speed = 75;
    if (this->weather == Weather::Snow)
        average_speed = 45;
}
