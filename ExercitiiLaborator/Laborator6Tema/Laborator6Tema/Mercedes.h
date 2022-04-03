#pragma once

#include "Car.h"

class Mercedes : public Car {
  public:
    Mercedes();
    char* GetName() const;
    float GetFuelCapacity() const;
    float GetFuelCosumption() const;
    int GetSpeed() const;
    void SetWeather(Weather weather);
};