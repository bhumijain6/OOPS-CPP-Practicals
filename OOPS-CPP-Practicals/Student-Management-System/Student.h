#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    int rollNo;
    float marks;

public:
    Student(int r, string n, int a, float m);

    void display() const override;

    int getRollNo() const;
    string getName() const;
    int getAge() const;
    float getMarks() const;

    void updateMarks(float m);
};

#endif