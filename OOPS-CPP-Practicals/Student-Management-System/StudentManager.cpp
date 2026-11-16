#include "StudentManager.h"
#include "StudentException.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <stdexcept>

using namespace std;

void StudentManager::addStudent() {
    int r, a;
    float m;
    string n;

    cout << "Enter Roll No: ";
    cin >> r;

    for (const auto& s : students) {
        if (s.getRollNo() == r)
            throw runtime_error("Roll number already exists.");
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, n);

    cout << "Enter Age: ";
    cin >> a;

    cout << "Enter Marks: ";
    cin >> m;

    students.emplace_back(r, n, a, m);
    cout << "Student added successfully!\n";
}

void StudentManager::displayStudents() const {
    if (students.empty()) {
        cout << "No records found.\n";
        return;
    }

    for (const auto& s : students)
        s.display();
}

void StudentManager::searchStudent() const {
    int r;
    cout << "Enter Roll No: ";
    cin >> r;

    auto it = find_if(students.begin(), students.end(),
        [r](const Student& s) {
            return s.getRollNo() == r;
        });

    if (it == students.end())
        throw StudentNotFound();

    it->display();
}

void StudentManager::updateStudent() {
    int r;
    float m;

    cout << "Enter Roll No: ";
    cin >> r;

    auto it = find_if(students.begin(), students.end(),
        [r](const Student& s) {
            return s.getRollNo() == r;
        });

    if (it == students.end())
        throw StudentNotFound();

    cout << "Enter new marks: ";
    cin >> m;

    it->updateMarks(m);
    cout << "Marks updated!\n";
}

void StudentManager::deleteStudent() {
    int r;
    cout << "Enter Roll No: ";
    cin >> r;

    auto it = remove_if(students.begin(), students.end(),
        [r](const Student& s) {
            return s.getRollNo() == r;
        });

    if (it == students.end())
        throw StudentNotFound();

    students.erase(it, students.end());
    cout << "Student deleted!\n";
}

void StudentManager::saveToFile() const {
    ofstream file("students.txt");

    if (!file)
        throw runtime_error("Unable to open file.");

    for (const auto& s : students) {
        file << s.getRollNo() << "|"
             << s.getName() << "|"
             << s.getAge() << "|"
             << s.getMarks() << "\n";
    }
}

void StudentManager::loadFromFile() {
    ifstream file("students.txt");

    if (!file)
        return;

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string r, n, a, m;

        getline(ss, r, '|');
        getline(ss, n, '|');
        getline(ss, a, '|');
        getline(ss, m, '|');

        try {
            students.emplace_back(stoi(r), n, stoi(a), stof(m));
        }
        catch (...) {
            cout << "Skipping invalid record.\n";
        }
    }
}