#include <iostream>
#include <string>
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
    cout << "*****Input Admin Data*****\n"
    << "Admin Title: ";
    cin >> title;

    cout << "\nAdmin Responsibility: ";
    cin >> responsibility;
    
    cout << "\nAdmin's Supervisor: ";
    cin >> supervisor;
}

void Administrator::print(ostream& ost = cout) { //output object data to screen/file
    ost << "*****Input Admin Data*****\n"
    << "Admin Title: " << title
    << "\nAdmin Responsibility: " << responsibility
    << "\nAdmin's Supervisor: " << supervisor;
}

void Administrator::print_check() { //Overload member function print_check
    set_net_pay(salary);
    cout << "\n__________________________________________________\n";
    cout << "Pay to the order of " << get_name( ) << endl;
    cout << "The sum of " << get_net_pay( ) << " Dollars\n";
    cout << "_________________________________________________\n";
    cout << "Check Stub NOT NEGOTIABLE \n";
    cout << "Employee Number: " << get_ssn( ) << endl;
    cout << "Salaried Employee. Regular Pay: "
    << salary << endl;
    cout << "Administrator. Title: " << title << endl;
    cout << "Responsibility: " << responsibility << endl;
    cout << "Immediate Supervisor: " << supervisor << endl;
    cout << "_________________________________________________\n";
}