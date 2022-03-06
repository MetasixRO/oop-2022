#include "NumberList.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS


int main() {
    NumberList p;
    p.Init();
    int x, i = 0, n;
    std::cout << "Introduceti numarul de valori : ";
    std::cin >> n;
    std::cout << "Introduceti valorile dorite : ";
    while (i < n) {
        std::cin >> x;
        p.Add(x);
        i++;
    }
    p.Sort();
    p.Print();

return 0;
}