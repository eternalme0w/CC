#include "Property.h"


Property::Property(double worth) : worth(worth) {}

double Property::get_worth() const {

    return worth;
}

double Property::income_tax_calculation() const {

    return worth * 0.13;
}


void Property::set_worth(double worth) {

    this->worth = worth;
}

