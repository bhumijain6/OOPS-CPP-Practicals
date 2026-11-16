
#include <iostream>
#include <memory>
using namespace std;

class Demo {
public:
    Demo() {
        cout << "Memory allocated" << endl;
    }

    ~Demo() {
        cout << "Memory released" << endl;
    }
};

int main() {

    // Using unique_ptr
    {
        unique_ptr<Demo> p1 = make_unique<Demo>();
        cout << "Unique pointer in use" << endl;
    }

    // Using shared_ptr
    {
        shared_ptr<Demo> p2 = make_shared<Demo>();
        shared_ptr<Demo> p3 = p2;

        cout << "Reference count: "
             << p2.use_count() << endl;
    }

    cout << "All memory released automatically" << endl;

    return 0;
}
