/**
 * Lab 7_1
 * Vincent Saw
 * CMPE50
 * g++ -o Lab7_1.exe Lab7_1.cpp
 * ./Lab7_1.exe
**/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int COLS = 4;
int rows;
char ** cArr;
//char (*cArr)[COLS]; //Declare 2D array, array of *cArr ptrs

void outputSeats() {
    for (int i = 0; i < rows; i++) {
        cout << left << setw(3) << i+1 << " ";
        for (int j = 0; j < COLS; j++)
            cout << cArr[i][j] << " ";
        cout << "\n";
    }
}

void freeAirplaneArray() {
    for (int i = 0; i < rows; i++) { //Free and delete each row's columns
        delete [] cArr[i];
    }
    delete [] cArr; //Free and delete character array pointer
}

void enterSeats(istream& in) {
    int area, numEntries = 0;
    int r, c;
    area = COLS*rows;

    do {
        char cInput;
        cout << "Enter desired seat (Ex: 1A) [0Z to terminate]:\n";
        in >> r >> cInput;
        if (r == 0) { //If user wants to terminate
            break;
        }
        for (int i = 0; i < COLS; i++) { //Convert character into column index
            char temp = i+65;
            if (toupper(cInput) == temp)
                c = i+1;
        }
        if (cArr[r-1][c-1] != 'X') { //Check if filled
            cArr[r-1][c-1] = 'X';
            outputSeats();
            numEntries++;
        }
        else {
            cout << "Seat " << r << static_cast<char>(toupper(cInput)) << " already taken! Please try again.\n";
        }

    }  while (numEntries < area);

    freeAirplaneArray();
    if (r != 0)
        cout << "Airplane full! ";
    cout << "\nProgram terminating..." << endl;
}

int main() {
    cout << "How many rows of seats?: ";
    cin >> rows;

    cArr = new char*[rows]; //Allocate array of pointers

    for (int i = 0; i < rows; i++) { //Allo. rows and fill columns
        cArr[i] = new char[COLS]; //Allocate each row
        cArr[i][0] = 'A'; //Fill 2D array
        cArr[i][1] = 'B';
        cArr[i][2] = 'C';
        cArr[i][3] = 'D';
    }

    outputSeats();

    bool istreamChoice;
    cout << "Would you like to input via file(0) or console(1)?: ";
    cin >> istreamChoice;

    switch (istreamChoice) {
        case 0: {
            char fName[32];
            ifstream ifs;
            cout << "File name?: ";
            cin >> fName;
            ifs.open(fName);
            enterSeats(ifs);
            break;
        }
        case 1: {
            enterSeats(cin);
            break;
        }
    }

    return 0;
}


/**
****************** Algorithm ******************
1. Declare dynamic 2D array using "new", fill each row with ABCD
2. While # of entries is less than the area (cols*rows), take input from istream
    a. Do necessary character to column index conversion
    b. If seat isn't taken (seat index equal to 'X'), assign X to seat index and increment entry counter.
    Else display that the seat is taken, reiterate the while loop.
3. When user terminates or airplane is full (entries == area), delete the previously created dynamic 2D array

***************** Pseudocode ******************
int area, numEntries = 0;
int r, c;
area = COLS*rows;

do {
    char cInput;
    cout << "Enter desired seat (Ex: 1A) [0Z to terminate]:\n";
    in >> r >> cInput; //istream, either ifstream or cin
    if (r == 0) { //If user wants to terminate
        break;
    }
    for (int i = 0; i < COLS; i++) { //Convert character into column index
        char temp = i+65; //ASCII conversion
        if (toupper(cInput) == temp)
            c = i+1;
    }
    if (cArr[r-1][c-1] != 'X') { //Check if filled
        cArr[r-1][c-1] = 'X';
        outputSeats();
        numEntries++;
    }
    else {
        cout << "Seat " << r << static_cast<char>(toupper(cInput)) << " already taken! Please try again.\n";
    }

}  while (numEntries < area);

freeAirplaneArray();

*********** Output of Lab Exercise ************
---------------USING INPUT1.TXT----------------
How many rows of seats?: 7
1   A B C D 
2   A B C D
3   A B C D
4   A B C D
5   A B C D
6   A B C D
7   A B C D
Would you like to input via file(0) or console(1)?: 0
File name?: input1.txt
Enter desired seat (Ex: 1A) [0Z to terminate]:
1   X B C D
2   A B C D
3   A B C D
4   A B C D
5   A B C D
6   A B C D
7   A B C D
Enter desired seat (Ex: 1A) [0Z to terminate]:
1   X B C D
2   X B C D
3   A B C D
4   A B C D
5   A B C D
6   A B C D
7   A B C D
Enter desired seat (Ex: 1A) [0Z to terminate]:
1   X B C D
2   X B C D
3   X B C D
4   A B C D
5   A B C D
6   A B C D
7   A B C D
Enter desired seat (Ex: 1A) [0Z to terminate]:
1   X B C D
2   X B C D
3   X B C D
4   X B C D
5   A B C D
6   A B C D
7   A B C D
Enter desired seat (Ex: 1A) [0Z to terminate]:
1   X B C D
2   X B C D
3   X B C D
4   X B C D
5   X B C D
6   A B C D
7   A B C D
Enter desired seat (Ex: 1A) [0Z to terminate]:
1   X B C D
2   X B C D
3   X B C D
4   X B C D
5   X B C D
6   X B C D
7   A B C D
Enter desired seat (Ex: 1A) [0Z to terminate]:
1   X B C D
2   X B C D
3   X B C D
4   X B C D
5   X B C D
6   X B C D
7   X B C D
Enter desired seat (Ex: 1A) [0Z to terminate]:
1   X B C D
2   X X C D
3   X B C D
4   X B C D
5   X B C D
6   X B C D
7   X B C D
Enter desired seat (Ex: 1A) [0Z to terminate]:
1   X B C D
2   X X X D
3   X B C D
4   X B C D
5   X B C D
6   X B C D
7   X B C D
Enter desired seat (Ex: 1A) [0Z to terminate]:
1   X B C D
2   X X X X
3   X B C D
4   X B C D
5   X B C D
6   X B C D
7   X B C D
Enter desired seat (Ex: 1A) [0Z to terminate]:
1   X B C D
2   X X X X
3   X B C D
4   X B C D
5   X B C D
6   X B C D
7   X B C X
Enter desired seat (Ex: 1A) [0Z to terminate]:

Program terminating...

-----------------USING CONSOLE-----------------
How many rows of seats?: 2
1   A B C D 
2   A B C D
Would you like to input via file(0) or console(1)?: 1
Enter desired seat (Ex: 1A) [0Z to terminate]:
1A
1   X B C D
2   A B C D
Enter desired seat (Ex: 1A) [0Z to terminate]:
2D
1   X B C D
2   A B C X
Enter desired seat (Ex: 1A) [0Z to terminate]:
1A
Seat 1A already taken! Please try again.
Enter desired seat (Ex: 1A) [0Z to terminate]:
2C
1   X B C D
2   A B X X
Enter desired seat (Ex: 1A) [0Z to terminate]:
1B
1   X X C D
2   A B X X
Enter desired seat (Ex: 1A) [0Z to terminate]:
2A
1   X X C D 
2   X B X X
Enter desired seat (Ex: 1A) [0Z to terminate]:
1C
1   X X X D
2   X B X X
Enter desired seat (Ex: 1A) [0Z to terminate]:
2B
1   X X X D
2   X X X X
Enter desired seat (Ex: 1A) [0Z to terminate]:
1D
1   X X X X
2   X X X X
Airplane full! 
Program terminating...

**/