
#include <iostream>
using namespace std;

class BankAccount {
protected:
    string name;
    double balance;

public:
    void setDetails(string n, double b) {
        name = n;
        balance = b;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
public:
    void calculateInterest() {
        cout << "Interest: " << balance * 0.05 << endl;
    }
};

int main() {
    SavingsAccount s;

    s.setDetails("Rahul", 10000);
    s.display();
    s.calculateInterest();

    return 0;
}
