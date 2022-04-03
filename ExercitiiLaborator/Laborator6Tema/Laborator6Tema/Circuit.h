#pragma once
#include "Dacia.h"
#include "Car.h"
#include "Ford.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"
#include "Weather.h"

class Circuit {
    Car* Cars[20];
    int lenght;
    Car* FinishCars[20];
    Car* NotFinishCars[20];
    int finish_number;
    int not_finish_number;
    int cars_number;
    Weather weather;

    public:
    Circuit();

    void SetLenght(int);
    void SetWeather(Weather weather);

    void AddCar(Car *obj);

    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
    double FinishTime(int speed) const;
};