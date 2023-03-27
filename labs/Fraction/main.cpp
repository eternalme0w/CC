#include "Fraction.h"
#include <iostream>
#include <algorithm>

using namespace std;



int main() {

    try {

        Fraction fr;

        cin >> fr;
        cout << fr;

    } catch(invalid_argument &ex) {

        cout << ex.what();
    }


    return 0;
}