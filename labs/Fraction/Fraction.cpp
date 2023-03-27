#include "Fraction.h"

//-------------------------Constructors--------------------------------------------

Fraction::Fraction(void): numerator(0), denominator(1) {};

Fraction::Fraction(int n, int d) {

    setNumerator(n);
    setDenominator(d);

    reduce();
}

Fraction::Fraction(const char* str) {

    std::string s(str);

    std::string err = "The string must consist of two numbers separated by /\nFor example, 17/5";

    if (std::count(s.begin(), s.end(), '/') != 1) 
        throw std::invalid_argument(err);

    else {

        bool good_str = std::all_of(s.begin(), s.end(),
        [](unsigned char c) {

            return std::isdigit(c) || c == '/' || c == '-';
        });

        if (good_str) {

            std::string a = s.substr(0, s.find('/'));
            std::string b = s.substr(s.find('/') + 1);

            if ((a[a.length() - 1] == '-') || (b[b.length() - 1] == '-'))
                throw std::invalid_argument(err);

            try {

                setNumerator(stoi(a));
                setDenominator(stoi(b));
                reduce();

            } catch(std::invalid_argument &ex) {

                throw std::invalid_argument(ex.what());
            }

        } else throw std::invalid_argument(err);
    }

}

//---------------------------Seters-----------------------------------------------

void Fraction::setNumerator(int n) {

    numerator = n;
}

void Fraction::setDenominator(int d) {

    if (d <= 0) {

        throw std::invalid_argument("The denominator must belong to natural numbers.");

    } else denominator = d;
}

//----------------------------Geters-------------------------------------------------

int Fraction::getNumerator() const {

    return numerator;
}

int Fraction::getDenominator() const {

    return denominator;
}


//---------------------------Operators-----------------------------------------------

Fraction& Fraction::operator*= (const Fraction &fr) {

    setNumerator(numerator * fr.numerator);
    setDenominator(denominator * fr.denominator);

    reduce();

    return *this;
}

Fraction& Fraction::operator/= (const Fraction &fr) {

    setNumerator(numerator * fr.denominator);
    setDenominator(denominator * fr.numerator);

    reduce();

    return *this;
}

Fraction& Fraction::operator+= (const Fraction &fr) {

    if (denominator == fr.denominator) {

        setNumerator(numerator + fr.numerator);

    } else {

        setNumerator(numerator * fr.denominator + fr.numerator * denominator);
        setDenominator(denominator * fr.denominator);

    }

    reduce();

    return *this;
}

Fraction& Fraction::operator-= (const Fraction &fr) {

    Fraction copy = fr;
    *this += copy * -1;
    reduce();
    return *this;
}

Fraction operator* (const Fraction &a, const Fraction &b) {

    Fraction copy = a;
    copy *= b;
    return copy;
}

Fraction operator/ (const Fraction &a, const Fraction &b) {

    if (b.getNumerator() == 0) throw std::invalid_argument("Erorr: divide by zero.");

    Fraction copy = a;
    copy /= b;
    return copy;
}

Fraction operator+ (const Fraction &a, const Fraction &b) {

    Fraction copy = a;
    copy += b;
    return copy;
}

Fraction operator- (const Fraction &a, const Fraction &b) {

    Fraction copy = a;
    copy -= b;
    return copy;
}

bool operator<(const Fraction &a, const Fraction &b) {

    return ( a.getNumerator() * b.getDenominator() ) < ( b.getNumerator() * a.getDenominator() );
}

bool operator>(const Fraction &a, const Fraction &b) {

    return b < a;
}

bool operator==(const Fraction &a, const Fraction &b) {

    return !(a < b || a > b);
}

bool operator!=(const Fraction &a, const Fraction &b) {

    return !(a == b);
}

bool operator<=(const Fraction &a, const Fraction &b) {

    return (a == b || a < b);
}

bool operator>=(const Fraction &a, const Fraction &b) {

    return (a == b || a > b);
}



Fraction Fraction::operator* (const int c) {

    Fraction copy = *this;
    copy.setNumerator(copy.numerator * c);
    return copy;
}




//---------------------------Utils---------------------------------------------------

size_t Fraction::gcd(int a, int b) {

    return (b == 0) ? a : gcd(b, a % b);
}

void Fraction::reduce() {

    int num = numerator >= 0 ? numerator : numerator * -1;

    size_t gcd = this->gcd(num, denominator);

    if (gcd != 1) {

        numerator /= gcd;
        denominator /= gcd;
    }
}

void Fraction::out() const {

    std::cout << numerator << "/" << denominator;
}

