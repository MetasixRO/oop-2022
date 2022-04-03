#pragma once

#include "Car.h"

class Mazda : public Car {
  public:
    Mazda();
    char* GetName() const;
    float GetFuelCapacity() const;
    float GetFuelCosumption() const;
    int GetSpeed() const;
    void SetWeather(Weather weather);
};