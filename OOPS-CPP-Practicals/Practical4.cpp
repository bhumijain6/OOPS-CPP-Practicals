
#include <iostream>
using namespace std;

class Person {
public:
    string name;

    void showPerson() {
        cout << "Name: " << name << endl;
    }
};

// Single inheritance
class Student : public Person {
public:
    int rollNo;

    void showStudent() {
        cout << "Roll Number: " << rollNo << endl;
    }
};

// Multilevel inheritance
class GraduateStudent : public Student {
public:
    string degree;

    void showGraduate() {
        cout << "Degree: " << degree << endl;
    }
};

int main() {
    GraduateStudent g;

    g.name = "Aman";
    g.rollNo = 101;
    g.degree = "M.Tech";

    g.showPerson();
    g.showStudent();
    g.showGraduate();

    return 0;
}
