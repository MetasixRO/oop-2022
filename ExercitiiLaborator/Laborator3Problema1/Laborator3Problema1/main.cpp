#include "Math.h"
#include <iostream>

//Am modificat tipul de return pentru functiile cu parametrii double pentru a obtine un rezultat double, dar functioneaza si in tipul int

int main() {
    Math p;
    int G;
    double g;
    G = p.Add(5, 6);
    g = p.Add(3.4, 4.5);
    std::cout << G <<" "<< "Add(int int)"<< '\n' << g << " Add(double double)" <<'\n';
    G = p.Add(5, 1, 2, 3, 4, 5);
    std::cout << G << " Add(count ...)" << '\n';
    G = p.Add(5, 6, 7);
    std::cout << G << " Add(int int int)" <<'\n';
    g = p.Add(3.4, 4.5, 5.1);
    std::cout << g << " Add(double double double)" << '\n';
    int O;
    double s;
    O = p.Mul(3, 5);
    s = p.Mul(3.2, 4.5);
    std::cout << O << " Mul(int int)" << '\n' << s << " Mul(double double)" << '\n';
    O = p.Mul(3, 5, 7);
    s = p.Mul(3.2, 4.5, 6.3);
    std::cout << O << " Mul(int int int)" << '\n' << s << " Mul(double double double)" << '\n';
    std::cout << p.Add("Ana ", "Are") << '\n';
}