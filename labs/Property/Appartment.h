#include "Property.h"


class Appartment: public Property {

    double square;

public:

    Appartment(double, double);
    double tax_calculation() override;


};


