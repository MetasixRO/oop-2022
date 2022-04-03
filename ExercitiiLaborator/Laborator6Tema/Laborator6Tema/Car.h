#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Weather.h"
#include <cstring>


class Car {
  protected:
    char* CarName;
    float fuel_capacity;
    float fuel_consumption;
    int average_speed;
    Weather weather;

    public:
    virtual int GetSpeed() const = 0;
    virtual char* GetName() const = 0;
    virtual float GetFuelConsuption() const = 0;
    virtual float GetFuelCapacity() const   = 0;
    virtual void SetWeather(Weather weather) = 0;
};