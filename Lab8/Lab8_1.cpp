/**
 * Lab X_Y
 * Vincent Saw
 * CMPE50
 * g++ -o LabX_Y.exe LabX_Y.cpp
 * ./LabX_Y.exe
**/

#include <iostream>
#include "Polynomial.cpp"

using namespace std;

int main() {
    double pCo1[] = {0, 4, 1};
    double pCo2[] = {5, 1, 4};
    double pCo4[] = {5, 0, 0, 0, 0, 2, 3};
    Polynomial p1(pCo1, 2);
    Polynomial p2(pCo2, 2);
    Polynomial p3 = 4+p1;
    Polynomial p4(pCo4, 6);
    Polynomial p5 = p4*p2;
    Polynomial p6 = 2*p3;
    cout << p1 << endl;
    cout << "Eval: " << p1.evaluate(3) << endl;
    cout << p2 << endl;
    //cout << p2.evaluate(3) << endl;
    cout << p3 << endl;
    //cout << p3.evaluate(3) << endl;
    cout << p4 << endl;
    cout << p5 << endl;
    cout << p6 << endl;
    p3 = p3-4;
    cout << p3 << endl;
    return 0;
}


/**

*********** Output of Lab Exercise ************
4x+x^2
Eval: 21
5+x+4x^2
4+4x+x^2
5+2x^5+3x^6
25+5x+20x^2+10x^5+17x^6+11x^7+12x^8
8+8x+2x^2

**/