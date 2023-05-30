#include <iostream>

using namespace std;

class Base {

protected:

    int a = 0;

public:

    void f() {

        cout << "Base" << "\n\n";
    }
};

class Derived : private Base {

public:

    int b = 1;
    void g() {

        cout << "Derived" << a <<"\n\n";
    }

};

int main() {

    Derived d;

    //d.a;
    d.g();



    return 0;
}