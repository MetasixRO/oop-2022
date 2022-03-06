#pragma once
#include "Student.h"
#define _CRT_SECURE_NO_WARNINGS

class Global {
  private:
    Student students[10];
    unsigned count;

    public:
    void init();
    unsigned get_count() const;
    const Student& get_student_by_index(unsigned index) const;
    void add(const Student& student);
    unsigned comp_average(unsigned x,unsigned y);
    unsigned comp_math(unsigned x, unsigned y);
    unsigned comp_english(unsigned x, unsigned y);
    unsigned comp_history(unsigned x, unsigned y);
    unsigned comp_name(unsigned x, unsigned y);
    void print() const;
};

