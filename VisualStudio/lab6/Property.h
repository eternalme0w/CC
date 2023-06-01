#pragma once
#include "TAX_RATES.h"
#include "Ijsonio.h"
#include <iostream>


class Property : public Ijsonio {

protected:

    double worth;

public:

    Property(double);
    virtual ~Property() = default;

    virtual double tax_calculation() const = 0;
    double income_tax_calculation() const;

    double get_worth() const;
    void set_worth(double);

    virtual void out() const =  0;

    Property() = default;

};
