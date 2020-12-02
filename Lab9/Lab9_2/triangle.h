#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
using namespace std;

class Triangle : public Figure
{
    public:
        Triangle();
        void erase();
        void draw();
        void center();
};

#endif //TRIANGLE_H

//EXPLANATION IN LAB9_2.CPP