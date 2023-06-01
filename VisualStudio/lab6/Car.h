#pragma once
#include "Property.h"

class Car: public Property {

    double horsepower;

public:

    Car(double, double);
    double tax_calculation() const override;

    void out() const override;

   

};

