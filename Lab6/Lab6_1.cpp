/**
 * Lab 6_1
 * Vincent Saw
 * CMPE50
 * g++ -o Lab6_1.exe Lab6_1.cpp
 * ./Lab6_1.exe
**/

#include <iostream>
#include <fstream>

using namespace std;

class Resource {
    private:
        int status, writeTo;
    public:
        Resource() {
            status = 0;
            writeTo = 0;
        }
        Resource(int wT) {
            status = 0;
            if (wT == 1 || wT == 0)
                writeTo = wT;
            else
                cout << wT << "is not a valid writeTo number! (0 or 1).\n";
        }
        int getStatus() const;
        int getWriteTo() const;
        void setStatus(int stat);
        void setWriteTo(int write);
        void output(ostream &out_stream);
        friend bool check_status(Resource &res1, Resource &res2);
};

int Resource::getStatus() const { return status; }
int Resource::getWriteTo() const { return writeTo; }
void Resource::setStatus(int stat) { //CBR resource object to change it
    if (stat == 1 || stat == 0) //check if stat is 0 or 1
        status = stat;
    else 
        cout << stat << " is not a valid status number! (0 or 1).\n";
}
void Resource::setWriteTo(int write) { //CBR resource object to change it
    if (write == 1 || write == 0) //check if write is 0 or 1
        writeTo = write;
    else
        cout << write << " is not a valid writeTo number! (0 or 1).\n";
}
void Resource::output(ostream& out_stream) {
    out_stream << "----------\nStatus: " << status << "\nWriteTo: " << writeTo << "\n----------\n";
}

bool check_status(Resource &res1, Resource &res2) {
    if (res1.status == 1 && res2.status == 1) {
        cout << "Resource available.\n";
        return true;
    }
    else {
        cout << "Resource unavailable.\n";
        return false;
    }
}

int main() {
    ofstream ofs;
    ofs.open("Ex1Output.txt");
    Resource rObj = Resource(1);
    Resource rObj2;
    rObj.output(cout);
    rObj.output(ofs);
    rObj.setStatus(100);
    rObj.setStatus(1);
    rObj.setWriteTo(-5);
    rObj.setWriteTo(0);
    rObj.output(cout);
    rObj.output(ofs);
    rObj2.setStatus(1);
    rObj2.setWriteTo(1);
    cout << "Check Status: " << check_status(rObj, rObj2) << "\n";
    rObj.setStatus(0);
    cout << "Check Status: " << check_status(rObj, rObj2) << "\n";

    return 0;
}

/**
****************** Algorithm ******************
1. Create class Resource, and within this class:
    a. Declare two pvt. int vars status and writeTo
    b. Create public default constructor, directly initialize both private vars to 0
    c. Create single parameterized constructor with int parameter
        - Directly initialize status to 0 and writeTo to the parameter if
          the parameter is equal to 0 or 1
    d. Create two const int ret. member accessor functions for status and writeTo
    e. Create two void ret. member mutator functions for status and writeTo with an integer
       parameter 
    f. Create void return member function output with CBR ostream parameter 
       &out_stream and output status and writeTo by accessing them directly
    g. Create bool return friend function with 2 CBR Resource object parameters
       If both Resource objects' status equal 1, print Resource available
       Else print Resource unavailable.

***************** Pseudocode ******************
class Resource {
    private:
        int status, writeTo; //Two private vars status and writeTo
    public:
        Resource() {
            status = 0;
            writeTo = 0;
        }
        Resource(int wT) {
            status = 0;
            if (Constructor parameter wT is 0 or 1)
                writeTo = wT;
            else //non-binary
                //Print invalid num
        }
        int getStatus() const;
        int getWriteTo() const;
        void setStatus(int stat);
        void setWriteTo(int write);
        void output(ostream &out_stream);
        friend bool check_status(Resource &res1, Resource &res2);
};
int Resource::getStatus() const { return r.status; }
int Resource::getWriteTo() const { return r.writeTo; }
void Resource::setStatus(int stat) { 
    if (stat == 0 or 1) //check if stat is 0 or 1
        //Directly set status equal to stat
    else 
        //Print invalid num
}
void Resource::setWriteTo(int write) { 
    if (write == 0 or 1) //check if write is 0 or 1
        //Directly set writeTo equal to write
    else
        //Print invalid num
}
void Resource::output(ostream& out_stream) {
    out_stream << "\n" << status << "\n" << writeTo; //print some stuff
}
bool check_status(Resource &res1, Resource &res2) {
    if (res1.status == 1 && res2.status == 1) {
        cout << "Resource available.\n";
        return true;
    }
    else {
        cout << "Resource unavailable.\n";
        return false;
    }
}

*********** Output of Lab Exercise ************
***Console***
----------
Status: 0
WriteTo: 1
----------
100 is not a valid status number! (0 or 1).
-5 is not a valid writeTo number! (0 or 1).
----------
Status: 1
WriteTo: 0
----------

***Output File***
----------
Status: 0
WriteTo: 1
----------
----------
Status: 1
WriteTo: 0
----------


**/