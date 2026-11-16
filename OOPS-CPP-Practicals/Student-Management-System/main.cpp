#include <iostream>
#include "StudentManager.h"
#include "StudentException.h"

using namespace std;

int main() {
    StudentManager manager;
    manager.loadFromFile();

    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Marks\n";
        cout << "5. Delete Student\n";
        cout << "6. Save and Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: manager.addStudent(); break;
                case 2: manager.displayStudents(); break;
                case 3: manager.searchStudent(); break;
                case 4: manager.updateStudent(); break;
                case 5: manager.deleteStudent(); break;
                case 6:
                    manager.saveToFile();
                    cout << "Records saved. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }

    } while (choice != 6);

    return 0;
}