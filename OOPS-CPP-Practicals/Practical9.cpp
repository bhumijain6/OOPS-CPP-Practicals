
#include <iostream>
#include <exception>
using namespace std;

class BankingException : public exception {
public:
    const char* what() const noexcept override {
        return "Banking Error";
    }
};

class InsufficientBalance : public BankingException {
public:
    const char* what() const noexcept override {
        return "Insufficient Balance!";
    }
};

class InvalidAmount : public BankingException {
public:
    const char* what() const noexcept override {
        return "Invalid Transaction Amount!";
    }
};

class BankAccount {
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void withdraw(double amount) {
        if (amount <= 0)
            throw InvalidAmount();

        if (amount > balance)
            throw InsufficientBalance();

        balance -= amount;
        cout << "Withdrawal Successful!" << endl;
        cout << "Remaining Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account(5000);

    try {
        account.withdraw(6000);
    }
    catch (const InvalidAmount &e) {
        cout << e.what() << endl;
    }
    catch (const InsufficientBalance &e) {
        cout << e.what() << endl;
    }
    catch (const BankingException &e) {
        cout << e.what() << endl;
    }

    return 0;
}
