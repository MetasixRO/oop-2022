#pragma once
#define _CRT_SECURE_NO_WARNINGS

class Number

{
    int base;
    char* value;
  public:
    Number(const char* value, int base); // where base is between 2 and 16 //

    Number();

    Number(int val);

    ~Number();

    Number(const Number& d);

    Number(Number&& obj);

    // add operators and copy/move constructor

    void SwitchBase(int newBase);

    void Print();

    int GetDigitsCount(); // returns the number of digits for the current number

    int GetBase(); // returns the current base

    friend Number operator+(const Number& a, const Number& b);

    friend Number operator-(const Number& a, const Number& b);
    friend Number& operator+=(Number& a, const Number& b);
    int ToDeci() const; // din baza oarecare in decimal

    void fromDeci(int base, int number);

    bool operator>(const Number& b);
    bool operator<(const Number& b);
    bool operator<=(const Number& b);
    bool operator>=(const Number& b);
    bool operator==(const Number& b);
    bool operator!=(const Number& b);
    char operator[](int index);
    Number& operator--();
    Number& operator--(int val);
    Number& operator=(const Number& b);
    Number& operator=(int nr);
    Number& operator=(const char* nr);
};

/* Number& ::operator+(const Number& a, const Number& b);
Number& ::operator-(const Number& a, const Number& b);
Number& ::operator+=(const Number& a, const Number& b);
*/

