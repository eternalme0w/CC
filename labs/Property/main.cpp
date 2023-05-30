#include<iostream>
#include<string>

#include "Appartment.h"
#include "Car.h"
#include "CountryHouse.h"
#include "Property.h"
#include "Owner.h"

using namespace std;

int main() {

    Appartment appartment(500, 100);
    Car car(500, 100);
    CountryHouse house(500, 100);

    Property &p1 = appartment;
    Property &p2 = car;
    Property &p3 = house;


    cout << p1.tax_calculation();

    //Owner a("serega", "231424");

    /* a.addProperty(p1);

    if (a.own(p1)) {

        cout << "true";
    } */

    

    
    
    return 0;
}
