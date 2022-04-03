#pragma once

#include "Car.h"

class Toyota : public Car {
  public:
    Toyota();
    char* GetName() const;
    float GetFuelCapacity() const;
    float GetFuelCosumption() const;
    int GetSpeed() const;
    void SetWeather(Weather weather);
};