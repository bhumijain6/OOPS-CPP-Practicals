#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <vector>
#include "Student.h"

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent();
    void displayStudents() const;
    void searchStudent() const;
    void updateStudent();
    void deleteStudent();
    void saveToFile() const;
    void loadFromFile();
};

#endif