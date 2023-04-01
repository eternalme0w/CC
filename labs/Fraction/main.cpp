#include "Fraction.h"

using namespace std;



int main() {

    std::stringstream ss;

    try {

        Fraction fr1("5/3");

        double x = (double)fr1;

        cout << x;




    } catch(invalid_argument &ex) {

        cout << ex.what();
    }


    return 0;
}