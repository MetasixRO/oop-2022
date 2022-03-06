#include "Student.h"
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

void Student::init() {
    name[0] = '\n';
    math    = 0.0;
    english = 0.0;
    history = 0.0;
}

void Student::set_name(const char* name) {
    strcpy(this->name, name);
}

const char* Student::get_name() const {
    return name;
}

double Student::get_average() const {
    return (math + history + english) / 3;
}

void Student::set_math(double grade_math) {
    this->math = grade_math;
}

void Student::set_history(double grade_history) {
    this->history = grade_history;
}

void Student::set_english(double grade_english) {
    this->english = grade_english;
}

double Student::get_math() const {
    return math;
}

double Student::get_history() const {
    return history;
}

double Student::get_english() const {
    return english;
}
