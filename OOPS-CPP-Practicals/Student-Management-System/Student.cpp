#include "Student.h"
#include "StudentException.h"

Student::Student(int r, string n, int a, float m)
    : Person(n, a), rollNo(r), marks(m) {
    if (m < 0 || m > 100)
        throw InvalidMarks();
}

void Student::display() const {
    cout << "\nRoll No: " << rollNo
         << "\nName: " << name
         << "\nAge: " << age
         << "\nMarks: " << marks
         << "\nGrade: " << (marks >= 90 ? "A" :
                            marks >= 75 ? "B" :
                            marks >= 60 ? "C" : "D")
         << "\n-------------------\n";
}

int Student::getRollNo() const { return rollNo; }
string Student::getName() const { return name; }
int Student::getAge() const { return age; }
float Student::getMarks() const { return marks; }

void Student::updateMarks(float m) {
    if (m < 0 || m > 100)
        throw InvalidMarks();

    marks = m;
}