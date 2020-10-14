/**
 * Lab 6_2
 * Vincent Saw
 * CMPE50
 * g++ -o Lab6_2.exe Lab6_2.cpp
 * ./Lab6_2.exe
**/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Rational {
    private:
        int num, denom;
    public:
        Rational() {
            num = 0;
            denom = 0;
        } 
        Rational(int n, int d) {
            num = n;
            denom = d;
        }
        void input(istream& is);
        void output(ostream& os);
        friend Rational add(Rational& r1, Rational& r2);
        friend Rational subtract(Rational& r1, Rational& r2);
        friend Rational multiply(Rational& r1, Rational& r2);
        friend Rational divide(Rational& r1, Rational& r2);
        friend bool equal(const Rational& r1, const Rational& r2);
        friend bool less_than(const Rational& r1, const Rational& r2);
};

int gcd(int n1, int n2) {
	int temp;
	while (n2 != 0) {
		// cout << "n2 = " << n2 << endl;
		temp = n1;
		n1 = n2;
		n2 = temp % n2;
	}
	return abs(n1);
}

void Rational::input(istream& is) {
    char backslash;
    is >> num >> backslash >> denom;
}
void Rational::output(ostream& os) {
    os << "Rational number: " << num << "/" << denom << "\n";
}

Rational add(Rational& r1, Rational& r2) { //add r1 to r2
    int tN1, tN2, tD;
    tN1 = r1.num*r2.denom;
    tN2 = r2.num*r1.denom;
    tD = r1.denom * r2.denom;
    tN1 += tN2;
    return Rational(tN1/gcd(tN1, tD), tD/gcd(tN1, tD));
}
Rational subtract(Rational& r1, Rational& r2) { //sub r2 from r1
    int tN1, tN2, tD;
    tN1 = r1.num*r2.denom;
    tN2 = r2.num*r1.denom;
    tD = r1.denom * r2.denom;
    tN1 -= tN2;
    return Rational(tN1/gcd(tN1, tD), tD/gcd(tN1, tD));
}
Rational multiply(Rational& r1, Rational& r2) { //mult r1 by r2
    int tN, tD;
    tN = r1.num*r2.num;
    tD = r1.denom*r2.denom;
    return Rational(tN/gcd(tN, tD), tD/gcd(tN, tD));
}
Rational divide(Rational& r1, Rational& r2) { //divide r1 by r2
    int tN, tD;
    tN = r1.num*r2.denom;
    tD = r1.denom*r2.num;
    return Rational(tN/gcd(tN, tD), tD/gcd(tN, tD));
}
bool equal(const Rational& r1, const Rational& r2) {
    int tN1, tN2;
    tN1 = r1.num*r2.denom;
    tN2 = r2.num*r1.denom;
    if (tN1 == tN2)
        return true;
    else
        return false;
}
bool less_than(const Rational& r1, const Rational& r2) {
    int tN1, tN2;
    tN1 = r1.num*r2.denom;
    tN2 = r2.num*r1.denom;
    if (tN1 < tN2)
        return true;
    else
        return false;
}

/*****************************************/
int main() {

    Rational r1;
    cout << "Enter rational number r1 (n/d): ";
    r1.input(cin);

    Rational r2;
    cout << "Enter rational number r2 (n/d): ";
    r2.input(cin);

    Rational rAdd = add(r1, r2);
    Rational rSub = subtract(r1, r2);
    Rational rMult = multiply(r1, r2);
    Rational rDiv = divide(r1, r2); 
    cout << "r1 --> ";
    r1.output(cout);
    cout << "r2 --> ";
    r2.output(cout);
    cout << "****Operations on r1 and r2****\n";
    cout << "Add --> ";
    rAdd.output(cout);
    cout << "Sub --> ";
    rSub.output(cout);
    cout << "Mult --> ";
    rMult.output(cout);
    cout << "Div --> ";
    rDiv.output(cout);
    cout << "****Bool checking functions****\n";
    cout << "r1 and r2 equal(1) or not(0)? " << equal(r1,r2) << "\n";
    cout << "r1 less than r2(1) or not(0)? " << less_than(r1,r2) << endl;

    return 0;
}


/**
****************** Algorithm ******************
1. Create class Rational and within this class:
    a. Declare num and denom private member vars
    b. Create default constructor, initialize num and denom to 0
    c. Create constructor w/ 2 args to initialize num and denom
    d. Declare member func. input & output as well as required friend functions
2. Rational::input:
    a. Declare temp char var to hold inputted backslash
    b. Insert istream into mem var num, then the backslash into the temp char var,
    then mem var denom
3. Rational::output:
    a. Extract mem var num and denom to output stream of type ostream
4. add:
    a. Convert r1 numerator
    b. Convert r2 numerator
    c. Find r1 and r2's common denominator
    d. Add r2 num to r1 num
    e. return Rational object using 2 arg constructor, and in the args divide
    new num and denom by GCD
5. subtract:
    a. Convert r1 numerator
    b. Convert r2 numerator
    c. Find r1 and r2's common denominator
    d. Subtract r2 num to r1 num
    e. return Rational object using 2 arg constructor, and in the args divide
    new num and denom by GCD
6. multiply:
    a. Multiply r1 and r2 numerator
    b. Multiply r1 and r2 denominator
    e. return Rational object using 2 arg constructor, and in the args divide
    new num and denom by GCD
7. divide:
    a. Multiply r1 and inverse of r2's numerator
    b. Multiply r1 and inverse of r2's denominator
    e. return Rational object using 2 arg constructor, and in the args divide
    new num and denom by GCD
8. equal:
    a. Convert r1 numerator
    b. Convert r2 numerator
    c. Since denominators are the same, perform equality operation on converted
    r1 and r2 numerator to determine if equal.
    d. if equal, return true
    e. else, return false
8. less_than:
    a. Convert r1 numerator
    b. Convert r2 numerator
    c. Since denominators are the same, perform less_than operation on converted
    r1 and r2 numerator to determine if converted r1 less than converted r2.
    d. if converted r1 less than converted r2, return true
    e. else, return false

***************** Pseudocode ******************
class Rational {
    private:
        int num, denom;
    public:
        Rational() { //default
            num = 0;
            denom = 0;
        } 
        Rational(int n, int d) { //take 2 args, 1 for num, and 1 for denom
            num = n;
            denom = d;
        }
        void input(istream& is);
        void output(ostream& os);
        friend Rational add(Rational& r1, Rational& r2);
        friend Rational subtract(Rational& r1, Rational& r2);
        friend Rational multiply(Rational& r1, Rational& r2);
        friend Rational divide(Rational& r1, Rational& r2);
        friend bool equal(const Rational& r1, const Rational& r2);
        friend bool less_than(const Rational& r1, const Rational& r2);
};
int gcd(int n1, int n2) { //Input num for n1 and denom for n2
	int temp;
	while (n2 != 0) {
		// cout << "n2 = " << n2 << endl;
		temp = n1;
		n1 = n2;
		n2 = temp % n2;
	}
	return abs(n1); //Return GCD
}
void Rational::input(istream& is) {
    char backslash;
    is >> num >> backslash >> denom; //insert into num, then temp var backslash for the backslash char, then denom
}
void Rational::output(ostream& os) {
    os << "Rational number: " << num << "/" << denom << "\n"; //Extract to output stream
}
Rational add(Rational& r1, Rational& r2) { //add r1 to r2
    int tN1, tN2, tD; //temp numerator vars and denominator var
    tN1 = r1.num*r2.denom; //convert r1 numerator
    tN2 = r2.num*r1.denom; //convert r2 numerator
    tD = r1.denom * r2.denom; //find common denominator
    tN1 += tN2; //Add r2 to r1
    return Rational(tN1/gcd(tN1, tD), tD/gcd(tN1, tD)); //Divide both num and denom by GCD to find normalized
}
Rational subtract(Rational& r1, Rational& r2) { //sub r2 from r1
    int tN1, tN2, tD; //temp numerator vars and denominator var
    tN1 = r1.num*r2.denom; //convert r1 numerator
    tN2 = r2.num*r1.denom; //convert r2 numerator
    tD = r1.denom * r2.denom; //find common denominator
    tN1 -= tN2; //Subtract r2 from r1
    return Rational(tN1/gcd(tN1, tD), tD/gcd(tN1, tD)); //Divide both num and denom by GCD to find normalized
}
Rational multiply(Rational& r1, Rational& r2) { //mult r1 by r2
    int tN, tD; //temp numerator and denominator var
    tN = r1.num*r2.num; //multiply r1 and r2 numerators
    tD = r1.denom*r2.denom; //multiply r1 and r2 denominators
    return Rational(tN/gcd(tN, tD), tD/gcd(tN, tD)); //Divide both num and denom by GCD to find normalized
}
Rational divide(Rational& r1, Rational& r2) { //divide r1 by r2
    int tN, tD; //temp numerator and denominator var
    tN = r1.num*r2.denom; //multiply r1 numerator by inverse of r2's denominator
    tD = r1.denom*r2.num; //multiply r1 denominator by inverse of r2's numerator
    return Rational(tN/gcd(tN, tD), tD/gcd(tN, tD)); //Divide both num and denom by GCD to find normalized
}
bool equal(const Rational& r1, const Rational& r2) {
    int tN1, tN2; //temp numerator vars
    tN1 = r1.num*r2.denom; //convert r1 num
    tN2 = r2.num*r1.denom; //convert r2 num
    if (tN1 == tN2) //if converted r1 and r2 numerators are equal (because same denominator), return true
        return true; //returns 1
    else
        return false; //returns 0
}
bool less_than(const Rational& r1, const Rational& r2) {
    int tN1, tN2; //temp numerator vars
    tN1 = r1.num*r2.denom;
    tN2 = r2.num*r1.denom;
    if (tN1 less than tN2) //if converted r1 num less than r2 num (because same denominator), return true
        return true; //returns 1
    else
        return false; //returns 0
}
int main() { //Test program
    Rational r1;
    cout << "Enter rational number r1 (n/d): ";
    r1.input(cin);
    Rational r2;
    cout << "Enter rational number r2 (n/d): ";
    r2.input(cin);
    Rational rAdd = add(r1, r2);
    Rational rSub = subtract(r1, r2);
    Rational rMult = multiply(r1, r2);
    Rational rDiv = divide(r1, r2); 
    cout << "r1 --> ";
    r1.output(cout);
    cout << "r2 --> ";
    r2.output(cout);
    cout << "****Operations on r1 and r2****\n";
    cout << "Add --> ";
    rAdd.output(cout);
    cout << "Sub --> ";
    rSub.output(cout);
    cout << "Mult --> ";
    rMult.output(cout);
    cout << "Div --> ";
    rDiv.output(cout);
    cout << "****Bool checking functions****\n";
    cout << "r1 and r2 equal(1) or not(0)? " << equal(r1,r2) << "\n";
    cout << "r1 less than r2(1) or not(0)? " << less_than(r1,r2) << endl;
    return 0;
}

*********** Output of Lab Exercise ************
---Output 1---
Enter rational number r1 (n/d): -5/4
Enter rational number r2 (n/d): 6/3
r1 --> Rational number: -5/4
r2 --> Rational number: 6/3
****Operations on r1 and r2****
Add --> Rational number: 3/4
Sub --> Rational number: -13/4
Mult --> Rational number: -5/2
Div --> Rational number: -5/8
****Bool checking functions****
r1 and r2 equal(1) or not(0)? 0
r1 less than r2(1) or not(0)? 1

---Output 2---
Enter rational number r1 (n/d): -8/4
Enter rational number r2 (n/d): -6/3
r1 --> Rational number: -8/4
r2 --> Rational number: -6/3
****Operations on r1 and r2****
Add --> Rational number: -4/1
Sub --> Rational number: 0/1
Mult --> Rational number: 4/1
Div --> Rational number: -1/-1
****Bool checking functions****
r1 and r2 equal(1) or not(0)? 1
r1 less than r2(1) or not(0)? 0

**/