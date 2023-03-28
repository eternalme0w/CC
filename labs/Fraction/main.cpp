#include "Fraction.h"
#include <iostream>
#include <algorithm>

using namespace std;



int main() {

    try {

        Fraction fr("0/2");

        cout << (fr + "5/2");



    } catch(invalid_argument &ex) {

        cout << ex.what();
    }


    return 0;
}