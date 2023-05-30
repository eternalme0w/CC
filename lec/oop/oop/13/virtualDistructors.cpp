#include <iostream>

using namespace std;

class Base {

    int *a = new int();

};

class Direved: public Base {

    int *b = new int();
};

int main() {

    Base* b = new Direved();
    delete b;

    return 0;
}