#include "Car.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Toyota.h"
#include "Dacia.h"
#include "Mazda.h"
#include "Circuit.h"
#include <iostream>

int main() {
    Circuit c;
    c.SetLenght(100);
    c.SetWeather(Weather::Sunny);
    c.AddCar(new Dacia());
    c.AddCar(new Ford());
    c.AddCar(new Mazda());
    c.AddCar(new Mercedes());
    c.AddCar(new Toyota());
    c.Race();
    c.ShowFinalRanks();
    c.ShowWhoDidNotFinish();
    return 0;
}