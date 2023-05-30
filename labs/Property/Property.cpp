#include "Property.h"

Property::Property(double worth): worth(worth) {}

/* double Property::get_worth() {

    return worth;
} */

double Property::income_tax_calculation() {

    return worth * 0,13;
}


/* void Property::set_worth(double worth) {

    this->worth = worth;
} */
