/**
 * Lab 1_4
 * Vincent Saw
 * CMPE50
 **/

#include <iostream>

using namespace std;

int main() {
    bool prime = true; //initialize bool var with default value true
    int x = 50; //initialize int var with value k
    if (x == 3) //if x is 3, then skip loop and print that 3 is prime
        cout << x << " is a prime number.\n";
    else if (x < 3) //if x is less than 3, print error. Fail-safe.
        cout << x << " is an invalid number.\n";
    else { //if x isn't 3, then go into loop
        for (int i = 3; i < x; i++) {  //iterate from 3 to x-1
            for (int j = 2; j < i; j++) { //iterate from 2 to i-1
                if (i%j == 0) { //if i is divisble by j, i is not a prime number
                    prime = false; //deem current iteration of i as false
                    break; //exit the loop, unnecessary to keep on going
                }
            }
            if (prime) //checks if i has been deemed prime
                cout << i << " is a prime number\n"; //prints out i is a prime number
            prime = true; //resets bool var prime's value to true
        }
    }
    cout << "\n"; //new line

    return 0;
}

/**
 * Input of Lab Exercise 1.4: 50
 * Output of Lab Exercise 1.4:
    3 is a prime number
    5 is a prime number
    7 is a prime number
    11 is a prime number
    13 is a prime number
    17 is a prime number
    19 is a prime number
    23 is a prime number
    29 is a prime number
    31 is a prime number
    37 is a prime number
    41 is a prime number
    43 is a prime number
    47 is a prime number
 **/




//g++ -o Lab1_4.exe Lab1_4.cpp
//./Lab1_4.exe