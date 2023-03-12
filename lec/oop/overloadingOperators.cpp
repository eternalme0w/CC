#include <iostream>

struct Complex {

    double re = 0.0;
    double im = 0.0;

    Complex& operator+=(const Complex& z) {

        re += z.re;
        im += z.im;
        return *this;
    }

    Complex operator+(const Complex& z) {

        Complex copy = *this;
        copy += z;

        return copy;
    }

    Complex& operator++() {

        re += 1;
        im += 1;
        return *this;
    }

    Complex operator++(int) {

        Complex copy = *this;
        ++*this;
        return copy;

    }

    



};



int main() {

    return 0;
}