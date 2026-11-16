// Design and implement a class hierarchy for a real-world entity (e.g., BankAccount, Vehicle).
// Demonstrate access specifiers and member functions.
#include <iostream>
#include <string>
using namespace std;
class vehicle
{
private:
    double accountnumber;

public:
    string brand;
    int vnumber;
    int amount;
    string buyer;
    void newbrand(string newb)
    {
        brand=newb;
    }
    void display(){
        cout<<"Brand"<<" "<<brand<<endl;
        cout<<"Vehicle Number"<<" "<<vnumber<<endl;
        cout<<"Amount"<<" "<<amount<<endl;
        cout<<"Buyer Name"<<" "<<buyer<<endl;
    }
};

int main()
{
    vehicle v1;
    v1.brand="THAR";
    v1.vnumber=1999;
    v1.amount=1300000;
    
    v1.display();

    return 0;
}