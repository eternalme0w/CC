#include <iostream>

using namespace std;

struct Base {

    int x = 0;

    virtual void f() { 

        cout << "1\n";
    }

};

struct Derived: public Base {

    int y = 2;

    void f() {

        cout << "2\n";
    }

};


int main() {

    Derived d;
    //d.f(); // 2

    Base &bb = d;
    bb.f(); // 1

    //cout << "\n\nx: " << bb.x; // 0
    


    return 0;
}