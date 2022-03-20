#include "Sort.h"
#include <iostream>
#include <cstdarg>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

Sort::Sort(unsigned count, int min, int max) {
    elem = new int[count];
    this->count = count;
    for (unsigned i = 0; i < count; i++) {
        this->elem[i] = min + rand() % (max + 1 - min);
    }
}

Sort::Sort(int v[], unsigned count) {
    elem = new int[count];
    this->count = count;
    for (unsigned i = 0; i < count; i++) {
        this->elem[i] = v[i];
    }
}

Sort::Sort(unsigned count, ...) {
    elem = new int[count];
    this->count = count;
    va_list args;
    va_start(args, count);
    for (unsigned i = 0; i < count; i++) {
        int element = va_arg(args, int);
        this->elem[i] = element;
    }
    va_end(args);

}

Sort::Sort(char* sir) {
    int n = strlen(sir);
    unsigned count = 0;
    for (int i = 0; i < strlen(sir); i++)
        if (sir[i] == ',')
            count++;
    count++;
    elem = new int[count];
    this->count = count;
    unsigned j  = 0;
    char* p;
    p = strtok(sir, ",");
    while (p != NULL) {
        int rez = 0;
        for (int i = 0; p[i] != '\0'; ++i)
            rez = rez * 10 + p[i] - '0';
        this->elem[j] = rez;
        j++;
        p          = strtok(NULL, ",");
    }
}

void Sort::InsertSort(bool ascendent) {
    if (ascendent == false) {
        for (int i = 1; i < count; i++) {
            int key = elem[i];
            int j   = i - 1;
            while (j >= 0 && elem[j] > key) {
                elem[j + 1] = elem[j];
                j           = j - 1;
            }
            elem[j + 1] = key;
        }
        ascendent = true;
    }
}


void Sort::QuickSort(bool ascendent) {
     if (ascendent == false) {
        int i = 0;
         int L, R, piv, ok=1;
       const int const num = count;
         int* beg;
       beg    = new int[count];
         int* end;
       end = new int[count];
       beg[0] = 0;
       end[0] = count;
       while (i >= 0) {
           if (ok == 1) {
               L = beg[i];
               R = end[i] - 1;
               if (L < R) {
                   piv = elem[L];
                   if (i == count - 1) {
                       ok = 0;
                       break;
                   }
                   while (L < R) {
                       while (elem[R] >= piv && L < R) {
                           R--;
                       }
                       if (L < R) {
                           elem[L++] = elem[R];
                       }
                       while (elem[L] <= piv && L < R)
                           L++;
                       if (L < R)
                           elem[R--] = elem[L];
                   }
                   elem[L]    = piv;
                   beg[i + 1] = L + 1;
                   end[i + 1] = end[i];
                   end[i++]   = L;
               } else
                   i--;
           } else
               i--;
       }
    }     
}

void Sort::BubbleSort(bool ascendent) {
    if (ascendent == false) {
        for (int i=0;i<count-1;i++)
            for (int j=0;j<count-i-1;j++)
                if (elem[j] > elem[j + 1]) {
                    int aux = elem[j];
                    elem[j] = elem[j + 1];
                    elem[j + 1] = aux;
                }
        ascendent = true;
    }
}

void Sort::Print() {
    for (int i = 0; i < count; i++)
        std::cout << elem[i] << " ";
}

int Sort::GetElementsCount() {
    if (count > 0)
        return count;
    else
        return -1;
}

int Sort::GetElementFromIndex(int index) {
    if (index < count) {
        int x = elem[index];
        return x;
    } else
        return -1;
}
