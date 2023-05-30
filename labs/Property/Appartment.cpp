#include "Appartment.h"


Appartment::Appartment(double worth, double square): Property(worth), square(square) {}

double Appartment::tax_calculation() {

    return square > TAX_RATES::LIMIT_APPARTMENT_SQUARE ? worth * TAX_RATES::APPARTMENT_TAX : worth * TAX_RATES::APPARTMENT_LUXURY_TAX;
}

