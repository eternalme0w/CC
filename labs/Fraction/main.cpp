#include "Fraction.h"
#include <iostream>
#include <algorithm>

using namespace std;



int main() {

    try {

        Fraction fr1("4/2");
        
        Fraction f2 = "3/4" * fr1;

        //fr1.out();

    } catch(invalid_argument &ex) {

        cout << ex.what();
    }


    return 0;
}