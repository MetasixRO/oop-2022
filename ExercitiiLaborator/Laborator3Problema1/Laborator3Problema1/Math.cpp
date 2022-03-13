#include "Math.h"
#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS



int Math::Add(int a, int b) {
    int sum = 0;
    sum = a + b;
    return sum;
}

int Math::Add(int a, int b, int c) {
    int sum = 0;
    sum = a + b + c;
    return sum;
}

double Math::Add(double x, double y) {
    double suma = 0.0;
    suma = x + y;
    return suma;
}

double Math::Add(double x, double y, double z) {
    double  suma = 0.0;
    suma = x + y + z;
    return suma;
}

int Math::Mul(int a, int b) {
    int prod = 1;
    prod = a * b;
    return prod;

}

int Math::Mul(int a, int b, int c) {
   int  prod = 1;
    prod = a * b * c;
    return prod;
}

double Math::Mul(double x, double y) {
    double produs = 1.0;
    produs = x * y;
    return produs;
}

double Math::Mul(double x, double y, double z) {
    double  produs = 1.0;
    produs = x * y * z;
    return produs;
}

int Math::Add(int count, ...) {
    int* p = &count;
    int x, sum = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        x = va_arg(args, int);
        sum += x;
    }
    va_end(args);
    return sum;
}

char* Math::Add(const char* a, const char* b) {
    char* space;
    if (a == nullptr || b == nullptr)
        return nullptr;
    else {
        int len1  = strlen(a);
        int len2  = strlen(b);
        space = (char*) malloc(len1 + len2 +1);
        if (space) {
            memcpy(space, a, len1);
            memcpy(space + len1, b, len2);
            space[len1 + len2] = '\0';
        }
    }
    return space;
}
