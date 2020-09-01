/**
 * Lab 2_2
 * Vincent Saw
 * CMPE50
 **/

#include <iostream>

using namespace std;

int main() {
    char mainArr[100];
    int numChars = 0;
    cout << "Enter a maximum of 10 letters/characters:\n";
    cin >> mainArr;

    while (mainArr[numChars] != '.') {
        numChars++;
    }

    if (numChars > 10)
        cout << "You entered too many characters" << endl;
    else if (numChars < 1)
        cout << "Please enter at least one character" << endl;
    else {
        cout << "You entered: " << mainArr << "\n" << "In reverse: ";
        numChars--;
        for (int j = numChars; j >= 0; j--) {
            cout << mainArr[j];
        }

        cout << endl;   
    }
    return 0;
}


/**
 * Algorithm for Exercise 2 key code:
1. Declare main char array of large arbitrary size 100 and initialize integer variable numChars to 0 to store value of the number of characters that the user entered.
2. Give user prompt via cout and store user input via cin into the main char array of size 100.
3. Iterate n number of times until '.' using index i of the main char array as the check, with each iteration incrementing numChars.
4. Check if the number of characters numChars is larger than 10 or smaller than 1 and respond with the appropriate message and terminate, otherwise continue the program.
5. Restate what characters the user entered via cout.
6. Subtract 1 from numChars to omit the period
7. Iterate integer j down from numChars to 0, and within the function body print out index j of main char array via cout.

 * Pseudocode of key code
    char mainArr[100];
    int numChars = 0;
    cout << "Enter a maximum of 10 letters/characters:\n";
    cin >> mainArr; //store user input

    //Check how many numbers

    if (too few or too many characters)
        //Throw appropriate response
    else {
        //Tell user again what he/she entered
        //Subtract 1 from numChars to omit the period
        //For loop, iterate integer j down from numChars to 0
            //Print out index j of main char array via cout in the for loop
    }
    return 0;

 * Output of Lab Exercise 2:
Enter a maximum of 10 letters/characters:
.
Please enter at least one character

Enter a maximum of 10 letters/characters:
HelloHello.
You entered: HelloHello.
In reverse: olleHolleH

Enter a maximum of 10 letters/characters:
HelloHellol.
You entered too many characters
**/

//g++ -o Lab2_2.exe Lab2_2.cpp
//./Lab2_2.exe