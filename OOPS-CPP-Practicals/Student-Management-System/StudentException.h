#ifndef STUDENTEXCEPTION_H
#define STUDENTEXCEPTION_H

#include <stdexcept>
using namespace std;

class InvalidMarks : public runtime_error {
public:
    InvalidMarks() : runtime_error("Marks must be between 0 and 100.") {}
};

class StudentNotFound : public runtime_error {
public:
    StudentNotFound() : runtime_error("Student not found.") {}
};

#endif