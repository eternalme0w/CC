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

    friend std::ostream& operator<< (std::ostream &out, const Fraction& fr);
    friend std::istream& operator>> (std::istream &in, Fraction& fr);

    void out() const;

};

//--------------------Operators----------------------------------------------------

Fraction operator* (const Fraction &a, const Fraction &b);
Fraction operator/ (const Fraction &a, const Fraction &b);
Fraction operator+ (const Fraction &a, const Fraction &b);
Fraction operator- (const Fraction &a, const Fraction &b);

bool operator<(const Fraction &a, const Fraction &b);
bool operator>(const Fraction &a, const Fraction &b);
bool operator==(const Fraction &a, const Fraction &b);
bool operator!=(const Fraction &a, const Fraction &b);
bool operator<=(const Fraction &a, const Fraction &b);
bool operator>=(const Fraction &a, const Fraction &b);


//--------------------in/out streams-------------------------------------------------


std::ostream& operator<< (std::ostream &out, const Fraction& fr);
std::istream& operator>> (std::istream &in, Fraction& fr);