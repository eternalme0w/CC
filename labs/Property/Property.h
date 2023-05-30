#pragma once
#include <iostream>
#include "TAX_RATES.h"

class Property {

protected:

    double worth;

public:

    Property(double);
    virtual ~Property() = default;
    virtual double tax_calculation() = 0;


    double income_tax_calculation();
    double getWorth();

    //void set_worth(double);


};

