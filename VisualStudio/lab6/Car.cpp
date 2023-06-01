#include "Car.h"

Car::Car(double worth, double horsepower) : Property(worth), horsepower(horsepower) {}

double Car::tax_calculation() const {

    if (horsepower < TAX_RATES::LOW_HORSEPOWER) {

        return worth * TAX_RATES::CAR_TAX;

    }
    else {

        return horsepower > TAX_RATES::HIGH_HORSEPOWER ? worth * TAX_RATES::CAR_LUXURY_TAX : worth * TAX_RATES::CAR_TRUCK_TAX;
    }
}

void Car::out() const {

    printf("|  %-10s|    %-8.0f|    %-9.0f|    %-9.0f|     %-7.0f|\n", 
    "Car", horsepower, worth, income_tax_calculation(), tax_calculation());
}

