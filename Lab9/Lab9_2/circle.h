#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"
using namespace std;

class Circle : public Figure
{
    public:
        Circle();
        void erase();
        void draw();
        void center();
};

#endif //CIRCLE_H

//EXPLANATION IN LAB9_2.CPP
