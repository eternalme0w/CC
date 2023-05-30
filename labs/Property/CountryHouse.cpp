#include "CountryHouse.h"

CountryHouse::CountryHouse(double worth, double distanceFromCity): Property(worth), distanceFromCity(distanceFromCity) {}


double CountryHouse::tax_calculation() {

    return distanceFromCity > TAX_RATES::LIMIT_DISTANCE_FROM_CITY ? worth * TAX_RATES::COUNTRY_HOUSE_TAX : worth * TAX_RATES::APPARTMENT_TAX; 
}