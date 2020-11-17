/*
 * Polynomial.cpp
 *
 *  Created on: Oct 24, 2013
 *      Author: cltarng
 */


#include <iostream>
#include <cmath>
#include "Polynomial.h"
using namespace std;


Polynomial::Polynomial()
{
	degree = 10;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = 0;
	}
}

Polynomial::Polynomial(int degr)
{
	degree = degr;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = 0;
	}
}

Polynomial::Polynomial(const Polynomial &poly)
{
	degree = poly.get_degree();
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = poly.get_coeff(i);
	}
}

Polynomial::Polynomial(double cf[], int deg)
{
	degree = deg;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = cf[i];
	}
}

Polynomial::Polynomial(double ct) {
	degree = 0;
	coeff = new double[1];
	coeff[0] = ct;
}

Polynomial::~Polynomial()
{
	delete [] coeff;
}

int Polynomial::get_degree() const
{
	return degree;
}

double Polynomial::get_coeff(int deg) const
{
	if (degree < deg)
	{
		return 0;
		// The input degree is larger than the polynomial degree
	}
	return coeff[deg];
}

void Polynomial::set_coeff(int degr, double val)
{
	if (degree < degr)
	{
		cout << "Degree exceeded." << endl;
		return;
	}
	coeff[degr] = val;
}

// Evaluate the polynomial
double Polynomial::evaluate(double val)
{
	double sum = 0;
	for (int n = 0; n <= degree; n++) {
		sum += (pow(val, n)*coeff[n]); //x^n power * coeff
	}
	return sum;
}

// Assignment operator
void Polynomial::operator =(const Polynomial &poly)
{
	if (this == &poly)
	{
		// Copy to itself. Nothing to be done.
		return;
	}
	degree = poly.degree; //Copy degree

	delete [] coeff;

	double *coeffTemp = new double[degree+1];

	for (int i = 0; i <= degree; i++) { //Copy all elements of poly.coeff to dyn arr coeffTemp
		coeffTemp[i] = poly.coeff[i];
	}

	coeff = coeffTemp; //Assign dynamic address to coeff
}

// Overloaded operator +
Polynomial operator+(const Polynomial &pola, const Polynomial &polb) //poly + poly
{
	Polynomial polyTemp;
	int deg;
	if (pola.degree > polb.degree) { //Find largest degree
		deg = pola.degree;
	}
	else {
		deg = polb.degree;
	}

	delete [] polyTemp.coeff;

	polyTemp.coeff = new double[deg+1];
	polyTemp.degree = deg;
	
	for (int i = 0; i <= deg; i++) {
		polyTemp.coeff[i] = pola.coeff[i] + polb.coeff[i];
	}

	return polyTemp;
}

Polynomial operator+(const double num, const Polynomial &pola) //const + poly
{
	Polynomial polyTemp;
	delete [] polyTemp.coeff;
	polyTemp.degree = pola.degree;
	polyTemp.coeff = new double[pola.degree+1];

	for (int i = 0; i <= pola.degree; i++)
		polyTemp.coeff[i] = pola.coeff[i];

	polyTemp.coeff[0] += num;

	return polyTemp;
}

Polynomial operator+(const Polynomial &pola, const double num) //poly + const
{
	Polynomial polyTemp;
	delete [] polyTemp.coeff;
	polyTemp.degree = pola.degree;
	polyTemp.coeff = new double[pola.degree+1];

	for (int i = 0; i <= pola.degree; i++)
		polyTemp.coeff[i] = pola.coeff[i];

	polyTemp.coeff[0] += num;

	return polyTemp;
}

Polynomial operator-(const Polynomial &pola, const Polynomial &polb) //poly - poly
{
	Polynomial polyTemp;
	int deg;
	if (pola.degree > polb.degree) { //Find largest degree
		deg = pola.degree;
	}
	else {
		deg = polb.degree;
	}

	delete [] polyTemp.coeff;

	polyTemp.coeff = new double[deg+1];
	polyTemp.degree = deg;
	
	for (int i = 0; i <= deg; i++) {
		polyTemp.coeff[i] = pola.coeff[i] - polb.coeff[i];
	}

	return polyTemp;
}

Polynomial operator-(const double num, const Polynomial &pola) //const - poly
{
	Polynomial polyTemp;
	delete [] polyTemp.coeff;
	polyTemp.degree = pola.degree;
	polyTemp.coeff = new double[pola.degree+1];

	for (int i = 0; i <= pola.degree; i++)
		polyTemp.coeff[i] = pola.coeff[i];

	polyTemp.coeff[0] = num - pola.coeff[0];

	return polyTemp;
}

Polynomial operator-(const Polynomial &pola, const double num) //poly - const
{
	Polynomial polyTemp;
	delete [] polyTemp.coeff;
	polyTemp.degree = pola.degree;
	polyTemp.coeff = new double[pola.degree+1];

	for (int i = 0; i <= pola.degree; i++)
		polyTemp.coeff[i] = pola.coeff[i];

	polyTemp.coeff[0] -= num;

	return polyTemp;
}

Polynomial operator*(const Polynomial &polya, const Polynomial &polyb) //poly * poly
{
	Polynomial polyTemp;
	int deg = polya.degree + polyb.degree;

	delete [] polyTemp.coeff;

	polyTemp.degree = deg;
	polyTemp.coeff = new double[deg+1];

	for (int i = 0; i <= polya.degree; i++) {
		for (int j = 0; j <= polyb.degree; j++) {
			polyTemp.coeff[i+j] += polya.coeff[i] * polyb.coeff[j];
		}
	}

	return polyTemp;

}

Polynomial operator*(const double num, const Polynomial &pola)
{
	Polynomial polyTemp;
	delete [] polyTemp.coeff;

	polyTemp.degree = pola.degree;
	polyTemp.coeff = new double[pola.degree+1];

	for (int i = 0; i <= pola.degree; i++) {
		polyTemp.coeff[i] = num*pola.coeff[i];
	}

	return polyTemp;
}

Polynomial operator*(const Polynomial &pola, const double num)
{
	Polynomial polyTemp;
	delete [] polyTemp.coeff;

	polyTemp.degree = pola.degree;
	polyTemp.coeff = new double[pola.degree+1];

	for (int i = 0; i <= pola.degree; i++) {
		polyTemp.coeff[i] = num*pola.coeff[i];
	}

	return polyTemp;	
}

// Overloaded << operator
ostream& operator << (ostream& ost, const Polynomial &pol)
{
	bool first = false;
	for (int i = 0; i <= pol.degree; i++) {

		if (first && pol.coeff[i] > 0) {
			ost << "+";
		}

		if (pol.coeff[i] != 0) {
			first = true;
			
			if (pol.coeff[i] != 1) {
				ost << pol.coeff[i];
			}

			if (i == 1) {
				ost << "x";
			}
			else if (i > 1) {
				ost << "x^" << i;
			}
		}

		//if (i+1 != pol.degree && pol.coeff[i+1] > 0)
		//	ost << "+";
	}
	
	return ost;
}
