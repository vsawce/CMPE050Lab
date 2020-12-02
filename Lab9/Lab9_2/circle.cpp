#include <iostream>
#include "circle.h"

using namespace std;

Circle::Circle() {}

void Circle::erase() {
    cout << "Erase - Circle\n";
}

void Circle::draw() {
    cout << "Draw - Circle\n";
}

void Circle::center() {
    cout << "Center - Circle\n";
    erase();
    draw();
}

//EXPLANATION IN LAB9_2.CPP