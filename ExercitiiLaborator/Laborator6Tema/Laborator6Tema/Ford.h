#pragma once

#include "Car.h"

class Ford : public Car {
  public:
    Ford();
    char* GetName() const;
    float GetFuelCapacity() const;
    float GetFuelCosumption() const;
    int GetSpeed() const;
    void SetWeather(Weather weather);
};