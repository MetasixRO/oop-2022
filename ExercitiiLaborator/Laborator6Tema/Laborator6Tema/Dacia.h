#pragma once
#include "Car.h"

class Dacia : public Car {
  public:
    Dacia();
    char* GetName() const;
    float GetFuelCapacity() const;
    float GetFuelCosumption() const;
    int GetSpeed() const;
    void SetWeather(Weather weather);
};