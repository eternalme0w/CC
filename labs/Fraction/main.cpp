#include "Fraction.h"
#include <iostream>
#include <algorithm>

using namespace std;



int main() {

    try {

        Fraction fr1("1/2");
        
        /* Fraction fr2 = "3/4" + fr1;

        fr2.out(); */

        cout << (fr1 == "2/4");

    } catch(invalid_argument &ex) {

        cout << ex.what();
    }


    return 0;
}