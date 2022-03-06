#pragma once
#define _CRT_SECURE_NO_WARNINGS

class Student {
    char name[20];
    double math;
    double english;
    double history;

  public:
    void init();
    void set_name(const char* name);
    const char* get_name() const;
    double get_average() const;
    void set_math(double grade_math);
    void set_history(double grade_history);
    void set_english(double grade_english);
    double get_math() const;
    double get_history() const;
    double get_english() const;
};
