
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream file("students.csv",
                 ios::in | ios::out | ios::trunc);

    if (!file) {
        cout << "File opening failed!";
        return 1;
    }

    // Writing student records
    file << "Roll,Name,Marks\n";
    file << "1,Aman,90\n";
    file << "2,Riya,85\n";
    file << "3,Rahul,88\n";

    cout << "File written successfully!\n";

    // tellp: current writing position
    cout << "Writing Position: " << file.tellp() << endl;

    // seekg: move reading pointer
    file.seekg(0, ios::beg);

    cout << "\nStudent Records:\n";

    string line;

    while (getline(file, line)) {
        cout << line << endl;
    }

    // tellg: current reading position
    cout << "\nReading Position: " << file.tellg() << endl;

    // seekp: move writing pointer
    file.clear();
    file.seekp(0, ios::end);

    file << "4,Neha,92\n";

    cout << "\nNew record added successfully!";

    file.close();

    return 0;
}
