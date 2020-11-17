#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
    public:
        Complex();
        Complex(double r, double i);
        Complex(double real_part);
        bool operator==(const Complex &c);
        Complex operator+(const Complex &c);
        Complex operator-(const Complex &c);
        Complex operator*(const Complex &c);
        friend istream& operator>>(istream& ist, Complex &c);
        friend ostream& operator<<(ostream& ost, const Complex &c);
    private:
        double real;
        double imaginary;
};

const Complex i(0,1);

#endif