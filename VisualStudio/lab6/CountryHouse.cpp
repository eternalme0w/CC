#include "CountryHouse.h"


CountryHouse::CountryHouse(double worth, double distanceFromCity) : Property(worth), distanceFromCity(distanceFromCity) {}


double CountryHouse::tax_calculation() const {

    return distanceFromCity > TAX_RATES::LIMIT_DISTANCE_FROM_CITY ? worth * TAX_RATES::COUNTRY_HOUSE_TAX 
    : worth * TAX_RATES::APPARTMENT_TAX;
}

void CountryHouse::out() const {

    printf("|  %-10s|    %-8.0f|    %-9.0f|    %-9.0f|     %-7.0f|\n",
        "House", distanceFromCity, worth, income_tax_calculation(), tax_calculation());

}
