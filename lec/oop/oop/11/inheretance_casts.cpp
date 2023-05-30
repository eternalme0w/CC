#include <iostream>

using namespace std;

struct Base {

    int a = 0;

};

struct Derived: public Base {

    int b = 1;
};


int main() {

    Derived d;
    
    Base &b = d;

    cout << reinterpret_cast<Derived&>(b).b; 


    return 0;
}