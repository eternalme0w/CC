#include "Property.h"


class CountryHouse: public Property {

    double distanceFromCity;

public:

    CountryHouse(double, double);
    double tax_calculation() override;

};