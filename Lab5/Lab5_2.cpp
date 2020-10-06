/**
 * Lab 5_2
 * Vincent Saw
 * CMPE50
 * g++ -o Lab5_2.exe Lab5_2.cpp
 * ./Lab5_2.exe
**/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class CounterType {
    private:
        int counter;
    public:
        CounterType() { //a
            counter = 0;
            cout << "\nCounterType constructor set var counter to 0";
        }
        void increment(); //c
        void decrement(); //d, 0 check
        void SetCounter(int cnt); //b, set counter to arg val, 0 check
        int GetCounter(); //e, get function
        void OutputCount(ostream& os); //f
};

void CounterType::increment() { counter++; }

void CounterType::decrement() { //Check for 0
    if (counter > 0) {
        counter--;
        if (counter == 0)
            cout << "\nCounter is now at 0.";
    }
    else
        cout << "\nCannot decrement to negative number! Counter already at 0!";
}

void CounterType::SetCounter(int cnt) {
    if (cnt >= 0) {
        counter = cnt;
        if (cnt == 0)
            cout << "\nCounter is now at 0.";
    }
    else
        cout << "\nCannot set counter value to negative number!";
}

int CounterType::GetCounter() { return counter; }

void CounterType::OutputCount(ostream& os = cout) { os << "\nCounter: " << counter; }

int main() {
    CounterType ct;

    for (int i = 0; i < 5; i++)
        ct.increment();
    ct.OutputCount(cout);

    for (int i = 0; i < 6; i++)
        ct.decrement();
    ct.OutputCount(cout);

    ct.SetCounter(10);
    ct.SetCounter(-10);

    cout << "\nCount value based on GetCounter(): " << ct.GetCounter();

    cout << endl;
    return 0;
}




/**
***************** Algorithm *****************
For CounterType::increment() member function:
    1. Increment member var counter
For CounterType::decrement() member function:
    1. If member var counter is greater than 0, decrement. If new decremented
    value is equal to 0, print that it's 0.
    2. Else, print message that member var counter can't be decremented past 0
    and don't do anything
For CounterType::SetCounter(int cnt) member function:
    1. cnt is argument to be passed to member function
    2. If cnt is 0 or greater, then set member var counter to value of arg cnt.
    If cnt is 0, mention that member var counter is 0.
    3. Else, invalid cnt value because counter can't be negative, so do nothing
    except print that cnt is invalid
For CounterType::GetCounter() member function:
    1. Return member var counter
For CounterType::OutputCount(ostream& os) member function:
    1. Set default arg os to cout
    2. Insert counter into ostream variable os

***************** Pseudocode ******************
class CounterType {
    private:
        int counter;
    public:
        CounterType() { //a, constructor to set counter to 0
            counter = 0;
            cout << "\nCounterType constructor set var counter to 0";
        }
        void increment(); //c
        void decrement(); //d, 0 check
        void SetCounter(int cnt); //b, set counter to arg val, 0 check
        int GetCounter(); //e, get function
        void OutputCount(ostream& os); //f
};
void CounterType::increment() { counter++; } //increment, no need for 0 check
void CounterType::decrement() { //Check for 0
    if (member var counter greater than 0) {
        counter--; //decrement
        if (member var counter equal to 0) //Notify counter is 0
            cout << "\nCounter is now at 0.";
    }
    else //Cannot decrement 0, because it'll be negative. Print message.
        cout << "\nCannot decrement to negative number! Counter already at 0!";
}
void CounterType::SetCounter(int cnt) { //Check for 0
    if (arg cnt greater or equal to 0) { 
        counter = cnt;
        if (arg cnt equal to 0) //Notify counter is 0
            cout << "\nCounter is now at 0.";
    }
    else //Negative number attempted to be set, print message
        cout << "\nCannot set counter value to negative number!";
}
int CounterType::GetCounter() { return counter; }
void CounterType::OutputCount(ostream& os = cout) { os << "\nCounter: " << counter; }

*********** Output of Lab Exercise ************

CounterType constructor set var counter to 0
Counter: 5
Counter is now at 0.
Cannot decrement to negative number! Counter already at 0!
Counter: 0
Cannot set counter value to negative number!
Count value based on GetCounter(): 10

**/