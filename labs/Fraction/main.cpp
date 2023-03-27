#include "Fraction.h"
#include <iostream>
#include <algorithm>

using namespace std;



int main() {

    try {

        Fraction fr = frIn();

        fr.out();

    } catch(invalid_argument &ex) {

        cout << ex.what();
    }


    return 0;
}