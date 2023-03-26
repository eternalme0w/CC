#include "Fraction.h"
#include <iostream>
#include <algorithm>

using namespace std;



int main() {

    try {

        Fraction fr1("7.2/2.4");
        
        /* Fraction fr2("5/4"); */

        /* Fraction fr3 = fr1 - fr2; */

        fr1.out();

    } catch(invalid_argument &ex) {

        cout << ex.what();
    }


    return 0;
}