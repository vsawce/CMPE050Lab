/**
 * Lab 9_2
 * Vincent Saw
 * CMPE50
 * g++ Lab9_2.cpp figure.cpp circle.cpp triangle.cpp -o Lab9_2.exe
 * ./Lab9_2.exe
**/

#include <iostream>
#include "figure.h"
#include "circle.h"
#include "triangle.h"

using namespace std;

void myDraw(Figure *fig)
{
	fig->draw();
	cout << "\n myDraw: Derived class object calling center(). \n";
	fig->center();	
}

int main(){
	Figure *fig;
	Triangle *tri = new Triangle;

	fig = tri;
	fig->draw();
	cout << "\n Derived class Triangle object calling center(). \n";
	fig->center();

	myDraw(tri);

	Circle *cir = new Circle;
	fig = cir;
	cir->draw();
	cout << "\n Derived class Circle object calling center(). \n";
	cir->center();

	myDraw(cir);

	return 0;

}



/**
*********** Output of Lab Exercise ************
----------------- NON-VIRTUAL -----------------
Draw - Figure

 Derived class Triangle object calling center(). 
Center - Figure
Erase - Figure
Draw - Figure
Draw - Figure

 myDraw: Derived class object calling center().  
Center - Figure
Erase - Figure
Draw - Figure
Draw - Circle

 Derived class Circle object calling center().   
Center - Circle
Erase - Circle
Draw - Circle
Draw - Figure

 myDraw: Derived class object calling center().
Center - Figure
Erase - Figure
Draw - Figure


------------------- VIRTUAL -------------------
Draw - Triangle

 Derived class Triangle object calling center().
Center - Triangle
Erase - Triangle
Draw - Triangle
Draw - Triangle

 myDraw: Derived class object calling center().
Center - Triangle
Erase - Triangle
Draw - Triangle
Draw - Circle

 Derived class Circle object calling center().
Center - Circle
Erase - Circle
Draw - Circle
Draw - Circle

 myDraw: Derived class object calling center().
Center - Circle
Erase - Circle
Draw - Circle


***************** Explanation *****************
The non-virtual compilation assumes the definition of a 
function statically based on the pointer type

The virtual compilation assumes the definition of a
function dynamically based on the pointer type. It does
something called "late binding" which means that it chooses
definitions during run time instead of compile time.

Virtual functions allow you to use pointers more freely
to represent the value it is assigned to. Like if a Figure
pointer is initialized, then changed so that it points
to another pointer of type Player, calling a function
like erase() will assume the definition defined in Player because
Player has its own definition of erase() and the compiler
will use its definition with late binding.
Without virtual, the same example will assume the definition
defined in Figure because it was already selected at compile-time
**/