#include <iostream>
#include "triangle.h"
using namespace std;

Triangle::Triangle() {}

void Triangle::erase() {
    cout << "Erase - Triangle\n";
}

void Triangle::draw() {
    cout << "Draw - Triangle\n";
}

void Triangle::center() {
    cout << "Center - Triangle\n";
    erase();
    draw();
}

//EXPLANATION IN LAB9_2.CPP