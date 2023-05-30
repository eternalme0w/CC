#pragma once
#include <iostream>

class Property {

protected:

    double worth;

public:

    Property(double);
    virtual ~Property() = default;
    virtual double tax_calculation() {
        
        return 0;
    };


    double income_tax_calculation();
    double get_worth();
    void set_worth(double);


};

