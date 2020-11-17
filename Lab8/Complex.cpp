#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex() {
    real = 0;
    imaginary = 0;
}

Complex::Complex(double r, double i) {
    real = r;
    imaginary = i;
}

Complex::Complex(double real_part) {
    real = real_part;
    imaginary = 0;
}

bool Complex::operator==(const Complex &c) {
    if(real == c.real && imaginary == c.imaginary) {
        return true;
    }
    else {
        return false;
    }
}

Complex Complex::operator+(const Complex &c) {
    Complex cTemp;
    cTemp.real = real + c.real;
    cTemp.imaginary = imaginary + c.imaginary;
    return cTemp;
}

Complex Complex::operator-(const Complex &c) {
    Complex cTemp;
    cTemp.real = real - c.real;
    cTemp.imaginary = imaginary - c.imaginary;
    return cTemp;
}

Complex Complex::operator*(const Complex &c) {
    Complex cTemp;
    cTemp.real = (real*c.real) - (imaginary*c.imaginary);
    cTemp.imaginary = (real*c.imaginary) + (imaginary*c.real);
    return cTemp;
}

istream& operator>>(istream &ist, Complex &c) {
    ist >> c.real >> c.imaginary;
    return ist;
}

ostream& operator<<(ostream& ost, const Complex &c) {
    ost << c.real << '+' << c.imaginary << 'i';
    return ost;
}

