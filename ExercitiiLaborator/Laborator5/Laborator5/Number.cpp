#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <string>


Number::Number(const char* value, int base) {
    int l = strlen(value);
    this->value = new char[l + 1];
    this->base  = base;
    strcpy(this->value, value);
    this->value[l] = '\0';
}

Number::Number() {
    this->base = -1;
    this->value = nullptr;
}

Number::Number(int val) {
    base = 10;
    int nr = 0;
    int cv     = val;
    while (cv != 0) {
        nr++;
        cv = cv / 10;
    }
    this->value = new char[nr+1];
    this->value[nr] = '\0';
    int i= 0;
    while (val > 0) {
        this->value[nr-1-i] = char(val % 10 + '0');
        val            = val / 10;
        i++;
    }
}

Number::Number(const Number& d) {
    this->base = d.base;
    int l       = strlen(d.value);
    this->value = new char[l+1];
    strcpy(this->value, d.value);
    this->value[l] = '\0';
}

Number::Number(Number&& d) {
    this->value = d.value;
    d.value     = nullptr;
    this->base = d.base;
}


Number::~Number() {
    base = -1;
    delete value;
}

int Number::ToDeci()const {
    int len = strlen(this->value);
    int power = 1;
    int num   = 0;
    int i;

    for (i = len - 1; i >= 0; i--) {
        int cif;
        if (this->value[i] >= '0' && this->value[i] <= '9')
            cif = (int) this->value[i] - '0';
        else
            cif = (int) this->value[i] - 'A' + 10;
        num += cif* power;
        power = power * this->base;
    }
    return num;
}

void Number::fromDeci(int base, int number) {
    int cn    = number;
    int cif    = 0;
    this->base = base;
    while (cn != 0) {
        cif++;
        cn = cn / base;
    }
    int k  = 1;
    value= new char[cif + 1];
    value[cif] = '\0';
    while (number > 0) {
        char nr;
        if (number % base >= 0 && number % base <= 9)
            nr = (char) (number % base + '0');
        else
            nr = (char) (number % base - 10 + 'A');
        value[cif - k] = nr;
        number /= base;
        k++;
    }
}

void Number::SwitchBase(int newBase) {
    int nr = ToDeci();
    fromDeci(newBase, nr);
}

void Number::Print() {
    std::cout << "Numarul " << value << " se afla in baza " << base <<'\n';
}

int Number::GetDigitsCount() {
    int count = 0;
    count     = strlen(value);
    return count;
}

int Number::GetBase() {
    return base;
}

bool Number::operator>(const Number& b) {
    Number copie;
    int nr = GetDigitsCount();
    copie.value = new char[nr + 1];
    copie.value[nr] = '\0';
    copie.base      = this->base;
    int Vala        = copie.ToDeci();
    int Valb        = b.ToDeci();
    if (Vala > Valb)
        return true;
    return false;
    
}

bool Number::operator<(const Number& b) {
    Number copie;
    int nr          = GetDigitsCount();
    copie.value     = new char[nr + 1];
    copie.value[nr] = '\0';
    copie.base      = this->base;
    int Vala        = copie.ToDeci();
    int Valb        = b.ToDeci();
    if (Vala < Valb)
        return true;
    return false;
}

bool Number::operator<=(const Number& b) {
    Number copie;
    int nr          = GetDigitsCount();
    copie.value     = new char[nr + 1];
    copie.value[nr] = '\0';
    copie.base      = this->base;
    int Vala        = copie.ToDeci();
    int Valb        = b.ToDeci();
    if (Vala <= Valb)
        return true;
    return false;
}

bool Number::operator>=(const Number& b) {
    Number copie;
    int nr          = GetDigitsCount();
    copie.value     = new char[nr + 1];
    copie.value[nr] = '\0';
    copie.base      = this->base;
    int Vala        = copie.ToDeci();
    int Valb        = b.ToDeci();
    if (Vala >= Valb)
        return true;
    return false;
}

bool Number::operator==(const Number& b) {
    Number copie;
    int nr          = GetDigitsCount();
    copie.value     = new char[nr + 1];
    copie.value[nr] = '\0';
    copie.base      = this->base;
    int Vala        = copie.ToDeci();
    int Valb        = b.ToDeci();
    if (Vala == Valb)
        return true;
    return false;
}

bool Number::operator!=(const Number& b) {
    Number copie;
    int nr          = GetDigitsCount();
    copie.value     = new char[nr + 1];
    copie.value[nr] = '\0';
    copie.base      = this->base;
    int Vala        = copie.ToDeci();
    int Valb        = b.ToDeci();
    if (Vala != Valb)
        return true;
    return false;
}

char Number::operator[](int index) {
    return value[index];
}

Number& Number::operator--() {
    int nr = strlen(value);
    for (int i = 1; i < nr; i++)
        value[i - 1] = value[i];
    value[nr - 1] = '\0';
    return (*this);
}

Number& Number::operator--(int val) {
    int nr        = strlen(value);
    value[nr - 1] = '\0';
    return (*this);
}

Number& Number::operator=(const Number& b) {
    this->base = b.base;
    strcpy(value, b.value);
    return (*this);
}

Number& Number::operator=(int nr) {
    if (base == -1)
        fromDeci(10, nr);
    else
        fromDeci(this->base, nr);
    return (*this);
}

Number& Number::operator=(const char* nr) {
    int l = strlen(nr);
    this->value = new char[l + 1];
    strcpy(this->value, nr);
    return (*this);
}

Number operator+(const Number& a, const Number& b) {
    Number rezultat;
    int baseM;
    if (a.base > b.base)
        baseM = a.base;
    else
        baseM = b.base;

    int Vala = a.ToDeci();
    int Valb = b.ToDeci();
    int sum  = Vala + Valb;
    rezultat.fromDeci(baseM, sum);
    return rezultat;
}

Number operator-(const Number& a, const Number& b) {
    Number rezultat;
    int baseM;
    int sum = 0;
    if (a.base > b.base)
        baseM = a.base;
    else
        baseM = b.base;

    int Vala = a.ToDeci();
    int Valb = b.ToDeci();
    if (Vala > Valb)
        sum = Vala - Valb;
    else
        sum = Valb - Vala;
    rezultat.fromDeci(baseM, sum);
    return rezultat;
}

Number& operator+=(Number& a, const Number& b) {
    a = a + b;
    return a;
}

