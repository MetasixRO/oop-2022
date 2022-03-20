#include "Sort.h"
#include <iostream>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

int main() {
    
    int v[]={ 25, 34, 1, 7, 10 };
    unsigned count1 = 5;
    
 //Vector 1
    Sort d1{ v, count1 };
    bool asc = 0;
    d1.BubbleSort(asc);
    d1.Print();
    int length=d1.GetElementsCount();
    int poz2 = d1.GetElementFromIndex(1);
    std::cout << '\n';
    std::cout << "Numarul de elemente in d1 (realizat prin transmiterea unui vector si unui count) este " << length;
    std::cout << '\n';
    std::cout<< "Elementul de pe pozitia 2 in vectorul d1 ordonat prin BubbleSort este " << poz2;
    std::cout << '\n';
    
 //Vector 2   
    Sort d2{ 6, 3, 11 };
    std::cout << '\n';
    std::cout << "Vectorul d2 neordonat este : ";
    d2.Print();
    std::cout << '\n';
    std::cout << "Vectorul d2 (realizat prin atribuirea unui count, min si max) ordonat prin InsertSort este : ";
    d2.InsertSort(asc);
    d2.Print();
    std::cout << '\n';
    
    
 // Vector 3
    char cara[110] = { "12,253,20,5,30,500" };
    std::cout << '\n';
    Sort d3{ cara };
    d3.BubbleSort(asc);
    std::cout << "Valorile vectorului d3 (realizat printr-un sir char) sunt :";
    d3.Print();
    std::cout << '\n';
    
 // Vector 4
    Sort d4{ 7, 1, 25, 67, 37, 20, 8, 12 };
    std::cout << '\n';
    std::cout << "Valorile vectorului d4 prin parametrii variadici sunt : ";
    d4.Print();
    d4.QuickSort(asc);
    std::cout << '\n';
    std::cout << "Vectorul d4 ordonat are valorile : ";
    d4.Print();
    std::cout << '\n';


 //Vector5
    std::cout << '\n';
    Sort d5(3);
    std::cout << "Valorile lui d5 sunt : ";
    d5.Print();
}