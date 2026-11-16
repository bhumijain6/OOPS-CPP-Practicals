
#include <iostream>
#include <utility>
using namespace std;

class Demo {
    int *data;

public:
    // Default constructor
    Demo() {
        data = new int(0);
        cout << "Default Constructor\n";
    }

    // Parameterized constructor
    Demo(int x) {
        data = new int(x);
        cout << "Parameterized Constructor\n";
    }

    // Copy constructor
    Demo(const Demo &obj) {
        data = new int(*obj.data);
        cout << "Copy Constructor\n";
    }

    // Move constructor
    Demo(Demo &&obj) noexcept {
        data = obj.data;
        obj.data = nullptr;
        cout << "Move Constructor\n";
    }

    // Copy assignment
    Demo& operator=(const Demo &obj) {
        if (this != &obj) {
            int *temp = new int(*obj.data);
            delete data;
            data = temp;
        }
        return *this;
    }

    // Move assignment
    Demo& operator=(Demo &&obj) noexcept {
        if (this != &obj) {
            delete data;
            data = obj.data;
            obj.data = nullptr;
        }
        return *this;
    }

    void display() {
        if (data)
            cout << "Value: " << *data << endl;
    }

    // Destructor
    ~Demo() {
        delete data;
        cout << "Destructor Called\n";
    }
};

int main() {
    Demo d1;
    Demo d2(100);
    Demo d3(d2);
    Demo d4(move(d2));

    d1 = d3;
    d1 = move(d4);

    d1.display();

    return 0;
}
