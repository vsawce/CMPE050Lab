#include <iostream>
#include "figure.h"
using namespace std;

Figure::Figure() {}

void Figure::erase() {
    cout << "Erase - Figure\n";
}
void Figure::draw() {
    cout << "Draw - Figure\n";
}
void Figure::center() {
    cout << "Center - Figure\n";
    erase();
    draw();
}

//EXPLANATION IN LAB9_2.CPP