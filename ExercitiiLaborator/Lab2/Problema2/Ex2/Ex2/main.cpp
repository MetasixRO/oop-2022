#include "Global.h"
#include "Student.h"
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

Global get_students() {
    Student student1;
    student1.init();
    student1.set_name("Ion");
    student1.set_math(4.7);
    student1.set_history(8.9);
    student1.set_english(5.4);

    Student student2;
    student2.init();
    student2.set_name("Andrei");
    student2.set_math(9.6);
    student2.set_history(8.5);
    student2.set_english(9.8);

    Student student3;
    student3.init();
    student3.set_name("Alexandru");
    student3.set_math(5.6);
    student3.set_history(6.0);
    student3.set_english(5.1);

    Student student4;
    student4.init();
    student4.set_name("Robert");
    student4.set_math(4.3);
    student4.set_history(7.5);
    student4.set_english(6.8);

    Student student5;
    student5.init();
    student5.set_name("Ricardo");
    student5.set_math(5.6);
    student5.set_history(8.9);
    student5.set_english(10.0);

    Global student_list;
    student_list.init();
    student_list.add(student1);
    student_list.add(student2);
    student_list.add(student3);
    student_list.add(student4);
    student_list.add(student5);

    return student_list;
}

int main() {
    Global students = get_students();
    students.print();
    std::cout << '\n';

    unsigned val = students.get_count();
    for (unsigned i = 0; i < val; i++) {
        for (unsigned j = 0; j < val; j++) {
            if (i != j) {
                if (students.comp_average(i, j) == 0)
                    std::cout << "Studentul " << i + 1 << " are media EGALA cu studentul" << j + 1;
                else if (students.comp_average(i, j) == 1)
                    std::cout << "Studentul " << i + 1 << " are media mai MARE decat studentul" << j + 1;
                else
                    std::cout << "Studentul " << i + 1 << " are media mai MICA decat studentul" << j + 1;
                std::cout << '\n';
            }
        }
        std::cout << '\n';
    }  
}