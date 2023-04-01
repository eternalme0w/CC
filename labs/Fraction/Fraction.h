#pragma once
#include <iostream>
#include <sstream>
#include <algorithm>

class Fraction {

    int numerator;
    int denominator;

    size_t gcd(int, int);
    void reduce();

public:

    explicit operator double() const {

        double b = static_cast<double>(numerator) / denominator;
        return b;
    }
    
    explicit operator std::string() const {

        std::stringstream ss;
        ss << numerator << "/" << denominator;
        return ss.str();
    }
    
    Fraction(void);
    Fraction(const int, const int);
    Fraction(int c);

    Fraction(const char*);

    Fraction& operator*= (const Fraction&);
    Fraction& operator/= (const Fraction&);
    Fraction& operator+= (const Fraction&);
    Fraction& operator-= (const Fraction&);

    Fraction operator-();


    int getNumerator() const;
    int getDenominator() const;

    void setNumerator(const int);
    void setDenominator(const int);

    Fraction reciprocal();

    int binExp(int, size_t);

    void pow(size_t);
    void pow(int);

    

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

//------------------------type casts---------------------------------------------

