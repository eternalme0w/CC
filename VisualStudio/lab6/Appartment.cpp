#include "Appartment.h"

Appartment::Appartment(double worth, double square) : Property(worth), square(square) {}

double Appartment::tax_calculation() const {

    return square > TAX_RATES::LIMIT_APPARTMENT_SQUARE ? worth * TAX_RATES::APPARTMENT_TAX : worth * TAX_RATES::APPARTMENT_LUXURY_TAX;
}

void Appartment::out() const {

    printf("| %-11s|    %-8.0f|    %-9.0f|    %-9.0f|     %-7.0f|\n",
                "Appartment", square, worth, income_tax_calculation(), tax_calculation());
}
