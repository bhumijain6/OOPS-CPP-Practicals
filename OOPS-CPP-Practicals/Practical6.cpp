
#include <iostream>
using namespace std;

class Complex {
    int real, imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // Function overloading
    void display(int x) {
        cout << "Integer: " << x << endl;
    }

    void display(double x) {
        cout << "Double: " << x << endl;
    }

    // Operator overloading
    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    void show() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(10, 5), c2(3, 2), c3;

    c1.display(10);
    c1.display(5.5);

    c3 = c1 + c2;

    cout << "Addition of Complex Numbers: ";
    c3.show();

    return 0;
}
