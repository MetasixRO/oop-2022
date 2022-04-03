#include "Circuit.h"
#include <iostream>
#include "Car.h"
#include "Weather.h"
#include <string.h>
#include <stdio.h>

Circuit::Circuit() {
    cars_number = 0;
    finish_number = 0;
    not_finish_number = 0;
    lenght            = 0;
    weather           = Weather::Sunny;
}

void Circuit::SetLenght(int lenght) {
    this->lenght = lenght;
}

void Circuit::SetWeather(Weather weather) {
    this->weather = weather;
    for (int i = 0; i < cars_number; i++)
        Cars[i]->SetWeather(weather);
}

void Circuit::AddCar(Car *obj) {
    obj->SetWeather(this->weather);
    Cars[cars_number++] = obj;
}

void Circuit::Race() {
    for (int i = 0; i < cars_number; i++) {
        int distance = (int) (Cars[i]->GetFuelCapacity() / Cars[i]->GetFuelConsuption()) * 100 * 1000;
        if (distance < lenght)
            NotFinishCars[not_finish_number++] = Cars[i];
        else {
            FinishCars[finish_number] = Cars[i];
            int aux                   = finish_number;
            while (aux > 0) {
                if (FinishTime(FinishCars[aux]->GetSpeed()) < FinishTime(FinishCars[aux - 1]->GetSpeed())) {
                    Car* temp           = FinishCars[aux];
                    FinishCars[aux]     = FinishCars[aux - 1];
                    FinishCars[aux - 1] = temp;
                } else
                    break;
                aux--;
            }
            finish_number++;
        }
    }
}

void Circuit::ShowFinalRanks() {
    if (finish_number == 0)
        std::cout << "No car finished";
    else
        for (unsigned i = 0; i < finish_number; i++) {
            double time = FinishTime(FinishCars[i]->GetSpeed());
            int time_in_sec = (int) (time * 3600);
            int sec         = time_in_sec;
            int time_in_min = time_in_sec / 60;
            int min         = time_in_min % 60;
            int time_in_h   = time_in_min / 60;
            printf("%s | %02dh|%02dm|%02ds \n", FinishCars[i]->GetName(), time_in_h, min, sec);
        }
    std::cout << '\n';

}

void Circuit::ShowWhoDidNotFinish() {
    if (not_finish_number == 0)
        std::cout << "All cars finished \n";
    else {
        for (int i = 0; i < not_finish_number; i++)
            std::cout << NotFinishCars[i]->GetName() << " didn't finish" << '\n';
    }
}

double Circuit::FinishTime(int speed) const {
    return (double) (lenght * 1.00 / 1000) / speed;
}
