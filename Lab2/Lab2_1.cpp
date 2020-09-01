/**
 * Lab 2_1
 * Vincent Saw
 * CMPE50
 **/

#include <iostream>

using namespace std;

void Add(double d1, double d2); //Declare function Add that takes two doubles before main
void Add(int i1, int i2); //Declare function Add that takes two ints before main
void Add(char c1[], char c2[]); //Declare function Add that takes two char arrays before main

int main() {

    int userNo = 0; //init int userNo as user selection variable

    double n1 = 10.5; //init double n1
    double n2 = 1.4; //init double n2
    int n3 = 10; //init int n3
    int n4 = 2; //init int n4
    char str1[] = "Hello "; //init char[] str1
    char str2[] = "World!"; //init char[] str2

    cout << "Would you like to add two doubles(1), integers(2), or character arrays(3)? Enter the number.\n"; //Ask user

    cin >> userNo; //Store user input value to user selection variable

    if (userNo == 1) { //If user chooses double
        Add(n1,n2);
    }
    else if (userNo == 2) { //If user chooses integer
        Add(n3,n4);
    }
    else if (userNo == 3) { //If user chooses character array
        Add(str1,str2);
    }
    else { //Error
        cout << "You did not enter either 1, 2, or 3.\n"; 
    }

    return 0;
}

void Add(double d1, double d2) {
    cout << d1+d2 << endl;
}

void Add(int i1, int i2) {
    cout << i1+i2 << endl;
}

void Add(char c1[], char c2[]) {
    cout << c1;
    cout << c2 << endl;
}

/**
 * Algorithm for Exercise 1:
 1. Declare three Add() functions for each data type.
 2. In main: Initialize two variables with arbitrary values for each of the three data types, as well as a variable for storing user input.
 3. Ask user which data type he/she wants to add via cout.
 4. Store user input to the appropriate variable with cin.
 5. Based on user input, use if statements to determine which data type to add. Add an else for all other values out of range.
 6. Within each if statement, call the appropriate Add() function as per data type.
 7. Within each of the three Add() functions, refer to pseudocode
 

 * Pseudocode of function Add
void Add(dataType var1, dataType var2) {
    
    //if numerical data type
    cout << var1+var2;

    //if char array
    cout << var1;
    cout << var2;
}


 * Output of Lab Exercise 1:
Would you like to add two doubles(1), integers(2), or character arrays(3)? Enter the number.
1
11.9

Would you like to add two doubles(1), integers(2), or character arrays(3)? Enter the number.
2
12

Would you like to add two doubles(1), integers(2), or character arrays(3)? Enter the number.
3
Hello World!
**/

//g++ -o Lab2_1.exe Lab2_1.cpp
//./Lab2_1.exe