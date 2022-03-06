#include "Global.h"
#include <cstring>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

void Global::init() {
    count = 0;
}

unsigned Global::get_count() const {
    return count;
}

const Student& Global::get_student_by_index(unsigned index) const {
    return students[index];
    
}

unsigned Global::comp_average(unsigned x, unsigned y) {
    if (students[x].get_average() > students[y].get_average())
        return 1;
    if (students[x].get_average() == students[y].get_average())
        return 0;
    return -1;
}

unsigned Global::comp_math(unsigned x, unsigned y) {
    if (students[x].get_math() > students[y].get_math())
        return 1;
    if (students[x].get_math() == students[y].get_math())
        return 0;
    return -1;
}

unsigned Global::comp_english(unsigned x, unsigned y) {
    if (students[x].get_english() > students[y].get_english())
        return 1;
    if (students[x].get_english() == students[y].get_english())
        return 0;
    return -1;
}

unsigned Global::comp_history(unsigned x, unsigned y) {
    if (students[x].get_history() > students[y].get_history())
        return 1;
    if (students[x].get_history() == students[y].get_history())
        return 0;
    return -1;
}

unsigned Global::comp_name(unsigned x, unsigned y) {
    if (strcmp(students[x].get_name(), students[y].get_name()) == 0)
        return 0;
    if (strcmp(students[x].get_name(), students[y].get_name()) == 1)
        return 1;
    return -1;
}

void Global::print() const {
    for (unsigned i = 0; i < count; i++)
        std::cout << i + 1 << '.' << students[i].get_name() << ' ' << students[i].get_math() << ' '
                  << students[i].get_english() << ' ' << students[i].get_history() << ' ' << students[i].get_average()
                  << '\n';
}

void Global::add(const Student& student) {
    students[count] = student;
    count++;
}
