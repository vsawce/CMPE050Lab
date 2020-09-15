/**
 * LabExam1
 * Vincent Saw
 * CMPE50
 * g++ -o LabExam1.exe LabExam1.cpp
 * ./LabExam1.exe
**/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

#define width1 10
#define width2 20

using namespace std;

ifstream ifs;
ifstream ifs1;
ofstream ofs1;
const char spacer = ' ';
const int charSize = 100;
int userIn, userIn2, size, uSize, count, iArr[charSize];
double groceryArr[100], annualCost, highestCost, lowestCost, avgCost;
char userInChar, cArr[charSize];
char uCArr[charSize];

void groceryCost(ifstream& ifs);

int main() {
    
    /* 1 */
    do {
        cout << "Would you like to execute exercise 2(1), exercise 3(2), or end the program?(3): ";
        cin >> userIn;
        if  (userIn < 1 || userIn > 3)
            cout << "Enter a valid number.\n";
    } while (userIn < 1 || userIn > 3);

    switch(userIn) {
        case 1: { /* 2 */
            ifs.open("input2.txt");

            if (ifs.fail()) {
                cout << "Failed to open input file.\n";
                exit(1);
            }

            groceryCost(ifs);
            
            break;
        }
        case 2: { /* 3 */
            do {
                cout << "Would you like to input keyboard(1) or file(2): ";
                cin >> userIn2;
                if  (userIn2 < 1 || userIn2 > 2)
                    cout << "Enter a valid number.\n";
            } while (userIn2 < 1 || userIn2 > 2);

            switch (userIn2) {
                case 1: {
                    int countKB = 0;
                    cout << "You entered keyboard input.\nEnter some characters and end with a period:";
                    do {
                        cin >> userInChar;
                        cArr[countKB] = tolower(userInChar);
                        countKB++;
                    } while (userInChar != '.');

                    break;
                }
                case 2: {
                    cout << "You selected file input.\n";
                    ifs1.open("input3.txt");

                    if (ifs1.fail()) {
                        cout << "Couldn't open input file.\n";
                        exit(1);
                    }

                    for (int i = 0; i < charSize; i++) {
                        ifs1 >> cArr[i];
                        cArr[i] = tolower(cArr[i]);
                    }

                    ifs1.close();
                    break;
                }


            }

            count = 0;
            while (cArr[count] != '.') {
                count++;
            }

            cout << "\nCharacter array: ";
            for (int i = 0; i < count; i++) {
                cout << cArr[i] << " ";
            }

            bool addChar;
            uSize = 0;
            for (int i = 0; i < count; i++) {
                addChar = true;
                for (int j = 0; j < i; j++) {
                    if (cArr[j] == cArr[i])
                        addChar = false;
                }
                if (addChar) {
                    uCArr[uSize] = cArr[i];
                    uSize++;
                }
            }


            for (int i = 0; i < uSize; i++) {
                iArr[i] = 0;
                for (int j = 0; j < count; j++)
                    if (uCArr[i] == cArr[j]) {
                        iArr[i]++;
                    }
            }
            int numIdx; //Sort from big to small
            int tempInt;
            char tempChar;
            for (int i = 0; i < uSize-1; i++) {
                numIdx = i;
                for (int j = i+1; j < uSize; j++) {
                    if (iArr[numIdx] < iArr[j])
                        numIdx = j;
                }
                tempInt = iArr[i];
                tempChar = uCArr[i];
                iArr[i] = iArr[numIdx];
                uCArr[i] = uCArr[numIdx];
                iArr[numIdx] = tempInt;
                uCArr[numIdx] = tempChar;
            }

            ofs1.open("LabExamOutput1-3.txt");

            if (ofs1.fail()) {
                cout << "Couldn't open output file.\n";
                exit(1);
            }

            cout << "\n" << left << setw(width1) << setfill(spacer) << "Letter";
            ofs1 << left << setw(width1) << setfill(spacer) << "Letter";
            cout << left << setw(width2) << setfill(spacer) << "# of Occurrences";
            ofs1 << left << setw(width2) << setfill(spacer) << "# of Occurrences";

            for (int i = 0; i < uSize; i++) {
                cout << "\n" << left << setw(width1) << uCArr[i];
                ofs1 << "\n" << left << setw(width1) << uCArr[i];
                cout << left << setw(width2) << iArr[i];
                ofs1 << left << setw(width2) << iArr[i];
            }
            ofs1.close();

            break;
        }
        case 3: {//Terminate
            break;
        }
    }
    
    cout << "\nProgram terminated.\n";
    return 0;
}

void groceryCost(ifstream& ifs) {
    size = 0;
    while (ifs >> groceryArr[size]) { //Take double values from ifstream and store into groceryArr
        size++;
    }
    ifs.close();

    cout << "Grocery cost per month, from file: ";
    for (int i = 0; i < size; i++)
        cout << fixed << setprecision(2) << groceryArr[i] << " ";
    
    annualCost = 0.0;
    for (int j = 0; j < size; j++)
        annualCost += groceryArr[j];

    cout << "\nGrocery cost per year: ";
    cout << setprecision(2) << annualCost;

    int highIdx = 0;
    int lowIdx = 0;
    highestCost = groceryArr[highIdx];
    lowestCost = groceryArr[lowIdx];
    for (int k = 1; k < size; k++) {
        if (groceryArr[highIdx] < groceryArr[k]) 
            highIdx = k;
        
        if (groceryArr[lowIdx] > groceryArr[k])
            lowIdx = k;

    }
    cout << "\nHighest grocery cost: " << fixed << setprecision(2) << groceryArr[highIdx];
    cout << "\nLowest grocery cost: " << fixed << setprecision(2) << groceryArr[lowIdx];

    cout << "\nAverage grocery cost per month: ";
    avgCost = annualCost/12.0;
    cout << fixed << setprecision(2) << avgCost << endl;

}





/** OUTPUT:
 
** EXERCISE 2:
Would you like to execute exercise 2(1), exercise 3(2), or end the program?(3): 1
Grocery cost per month, from file: 19.40 10.40 84.23 9.20 0.58 194.57 85.60 0.99 49.59 67.00 69.69 420.42 
Grocery cost per year: 1011.67
Highest grocery cost: 420.42
Lowest grocery cost: 0.58
Average grocery cost per month: 84.31

Program terminated.



** EXERCISE 3 KB:
Would you like to execute exercise 2(1), exercise 3(2), or end the program?(3): 2
Would you like to input keyboard(1) or file(2): 1
You entered keyboard input.
Enter some characters and end with a period:Hello Hello WOrld !.

Character array: h e l l o h e l l o w o r l d ! 
Letter    # of Occurrences    
l         5                   
o         3                   
h         2                   
e         2                   
w         1                   
r         1                   
d         1                   
!         1                   
Program terminated.



** EXERCISE 3 FILE INPUT:
Would you like to execute exercise 2(1), exercise 3(2), or end the program?(3): 2
Would you like to input keyboard(1) or file(2): 2
You selected file input.

Character array: d o b e d o b o 
Letter    # of Occurrences    
o         3                   
d         2                   
b         2                   
e         1                   
Program terminated.



** TERMINATE PROGRAM:
Would you like to execute exercise 2(1), exercise 3(2), or end the program?(3): 3

Program terminated.

**/