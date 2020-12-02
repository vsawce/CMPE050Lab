/**
 * Lab 9_1
 * Vincent Saw
 * CMPE50
 * g++ Lab9_1.cpp employee.cpp salariedemployee.cpp administrator.cpp -o Lab9_1.exe
 * ./Lab9_1.exe
**/

#include <iostream>
#include "administrator.h"

using namespace std;

int main() {
    
    SalariedEmployee s;
    Administrator a("Jeffrey Epstein", "123-45-6789", 124509,
    "Financier","Pedophile", "The Elites");
    //s.print_check();
    //a.input_admin_data();
    a.print_check();
    return 0;
}


/**
****************** Algorithm ******************
1. In classes Employee and SalariedEmployee, switch private to
protected so inherited classes can access higher member variables
2. Inherit class SalariedEmployee into administrator.h
3. Create appropriate constructors according to the 
default and specific constructors of inheritance hierarchy
4. Create all necessary member functions


***************** Pseudocode ******************
-----administrator.h-----
#include "salariedemployee.h"

using namespace std;
class Administrator : public SalariedEmployee
{
    public:
        Administrator();
        Administrator(string the_name, string the_ssn, double the_weekly_salary,
        string the_title, string the_responsibility, string the_supervisor);
        void set_supervisor(string sName); //change supervisor name
        void input_admin_data(); //Read in admin data from keyboard
        void print(ostream& ost);
        void print_check(); //Overload member function print_check
    protected:
        string title; //mem var of type string, admin title
        string responsibility; //mem var of type string, responsibility
        string supervisor; //mem var of type string, administrator's supervisor name
        //salary taken care of in salariedemployee
};

-----administrator.cpp-----
#include "administrator.h"
using namespace std;

Administrator::Administrator()
:
SalariedEmployee(), title("No title yet"),
responsibility("No responsibility yet"),
supervisor("No supervisor yet")
{
}
Administrator::Administrator(string the_name, string the_ssn, double the_weekly_salary,
string the_title, string the_responsibility, string the_supervisor)
:
SalariedEmployee(the_name, the_ssn, the_weekly_salary), title(the_title),
responsibility(the_responsibility), supervisor(the_supervisor)
{
}
void Administrator::set_supervisor(string sName) { //change supervisor name
    supervisor = sName;
}
void Administrator::input_admin_data() { //Read in admin data from keyboard
    cin >> title;
    cin >> responsibility;
    cin >> supervisor;
}
void Administrator::print(ostream& ost = cout) { //output object data to screen/file
    ost << title << responsibility << supervisor;
}
void Administrator::print_check() { //Overload member function print_check
    //borrow definition from salariedemployee, similar format;
}

*********** Output of Lab Exercise ************

__________________________________________________
Pay to the order of Jeffrey Epstein
The sum of 124509 Dollars
_________________________________________________
Check Stub NOT NEGOTIABLE
Employee Number: 123-45-6789
Salaried Employee. Regular Pay: 124509
Administrator. Title: Financier
Responsibility: Pedophile
Immediate Supervisor: The Elites
_________________________________________________

**/