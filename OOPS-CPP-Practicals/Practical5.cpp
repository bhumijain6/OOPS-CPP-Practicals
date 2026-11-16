
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void area() override {
        float r = 5;
        cout << "Circle Area: " << 3.14 * r * r << endl;
    }
};

class Rectangle : public Shape {
public:
    void area() override {
        int l = 5, b = 4;
        cout << "Rectangle Area: " << l * b << endl;
    }
};

class Triangle : public Shape {
public:
    void area() override {
        float b = 6, h = 4;
        cout << "Triangle Area: " << 0.5 * b * h << endl;
    }
};

int main() {
    Circle c;
    Rectangle r;
    Triangle t;

    Shape *s;

    s = &c;
    s->area();

    s = &r;
    s->area();

    s = &t;
    s->area();

    return 0;
}
