#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
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

#endif //ADMINISTRATOR_H

