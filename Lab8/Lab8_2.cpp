/**
 * Lab X_Y
 * Vincent Saw
 * CMPE50
 * g++ -o LabX_Y.exe LabX_Y.cpp
 * ./LabX_Y.exe
**/

#include <iostream>
#include "Complex.cpp"

using namespace std;


int main() {
    Complex c1(4,5);
    Complex c2(1,2);
    Complex c3(4,5);
    Complex cInput;
    cout << "c1: " << c1 << "\nc2: " << c2 << "\nc3: " << c3 << "\n";
    cout << "c1 equal to c2?: " << (c1==c2) << "\n";
    cout << "c1 equal to c3?: " << (c1==c3) << "\n";
    cout << "c1 + c2: " << (c1+c2) << "\n";
    cout << "c1 - c2: " << (c1-c2) << "\n";
    cout << "c1 * c2: " << (c1*c2) << "\n";
    cout << "Enter a complex number (a+bi): ";
    cin >> cInput;
    cout << "Self-operations: " << "\n";
    cout << "+: " << (cInput+cInput) << "\n";
    cout << "-: " << (cInput-cInput) << "\n";
    cout << "* (squared): " << (cInput*cInput) << "\n";
    return 0;
}


/**
****************** Algorithm ******************
1. Constructors:
    a. Based on type of constructor, set real & imaginary
2. == Overloaded Operator:
    a. Check if lhs (this) real & imaginary equal to rhs (argument) real & imaginary
3. Arithmetic operators:
    a. Create a local Complex object to store stuff in
    b. Do math stuff, store results in local object
    c. Return local object
4. Stream friend functions:
    a. istream:
        - CBR istream (lhs) and Complex (rhs) object in parameters
        - Extract rhs Complex object's real and then imaginary member vars.
        - return istream obj
    b. ostream:
        - CBR ostream (lhs) and const Complex (rhs) object in parameters
        - Insert lhs Complex object's real and then imaginary member vars, with
          appropriate string formatting to represent a+bi form
        - return ostream obj

***************** Pseudocode ******************
Constructors:
Complex::Complex(parameters) {
    real = ?;
    imaginary = ?;
}

== Overloaded Operator:
bool Complex::operator==(const Complex &c) {
    if(real == c.real && imaginary == c.imaginary) {
        return true;
    }
    else {
        return false;
    }
}

For each overloaded arithmetic operator:
Complex Complex::operator(const Complex &c) {
    Complex cTemp;
    //Some respective complex math stuff
    return cTemp;
}

Stream friend functions:
istream& operator>>(istream &ist, Complex &c) {
    ist >> c.real >> c.imaginary;
    return ist;
}
ostream& operator<<(ostream& ost, const Complex &c) {
    ost << c.real << '+' << c.imaginary << 'i';
    return ost;
}

*********** Output of Lab Exercise ************
c1: 4+5i
c2: 1+2i
c3: 4+5i
c1 equal to c2?: 0
c1 equal to c3?: 1
c1 + c2: 5+7i
c1 - c2: 3+3i
c1 * c2: -6+13i
Enter a complex number (a+bi): 3+4i
Self-operations: 
+: 6+8i
-: 0+0i
* (squared): -7+24i

**/