#pragma once
#include <iostream>
#include <algorithm>

class Fraction {

    int numerator;
    int denominator;

    size_t gcd(int, int);
    void reduce();

public:
    
    Fraction(void);
    Fraction(const int, const int);

    Fraction(const char*);

    Fraction& operator*= (const Fraction&);
    Fraction& operator/= (const Fraction&);
    Fraction& operator+= (const Fraction&);
    Fraction& operator-= (const Fraction&);

    Fraction operator* (const int);

    int getNumerator() const;
    int getDenominator() const;

    void setNumerator(const int);
    void setDenominator(const int);

    void out() const;

    friend void frOut(const Fraction &fr);
    friend Fraction frIn();

};

Fraction operator* (const Fraction &a, const Fraction &b);
Fraction operator/ (const Fraction &a, const Fraction &b);
Fraction operator+ (const Fraction &a, const Fraction &b);
Fraction operator- (const Fraction &a, const Fraction &b);

void frOut(const Fraction &fr);
Fraction frIn();

bool operator<(const Fraction &a, const Fraction &b);
bool operator>(const Fraction &a, const Fraction &b);
bool operator==(const Fraction &a, const Fraction &b);
bool operator!=(const Fraction &a, const Fraction &b);
bool operator<=(const Fraction &a, const Fraction &b);
bool operator>=(const Fraction &a, const Fraction &b);