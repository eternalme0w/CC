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
    
    Fraction(const std::string);

    Fraction& operator*= (const Fraction&);
    Fraction& operator/= (const Fraction&);
    Fraction& operator+= (const Fraction&);
    Fraction& operator-= (const Fraction&);

    Fraction operator* (const Fraction&);
    Fraction operator/ (const Fraction&);
    Fraction operator+ (const Fraction&);
    Fraction operator- (const Fraction&);

    bool operator< (const Fraction&);
    bool operator> (const Fraction&);
    bool operator== (const Fraction&);
    bool operator!= (const Fraction&);
    bool operator>= (const Fraction&);
    bool operator<= (const Fraction&);

    Fraction operator* (const int);

    int getNumerator() const;
    int getDenominator() const;

    void setNumerator(const int);
    void setDenominator(const int);

    void out() const;

};