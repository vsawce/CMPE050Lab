/**
 * Lab 3_2
 * Vincent Saw
 * CMPE50
 **/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define kbIn 0
#define fileIn 1
#define colWidth 5

const char spacer = ' ';
ifstream ifs;
ofstream ofs;
int size = 0;
int numUnique = 1;
int inputArr[50], intArr[50][2], userIn;
char fUserIn[50];

void sortUnique();
void selectSort();
void sortCount();
void printColumns();

int main() {

    do {
        cout << "Would you like to input integers through keyboard(0) or file(1)? ";
        cin >> userIn;
        if (userIn != 0 && userIn != 1)
            cout << "Enter a valid number.\n";
    }
    while (userIn != 0 && userIn != 1);

    switch (userIn){
        case kbIn: {

            cout << "Enter up to 50 numbers (ctrl+d[unix] or ctrl+z[win] to terminate and add a space to the last char): ";
            cin >> inputArr[size];

            while (!cin.eof()) {
                size++;
                cin >> inputArr[size];
            } 

            selectSort();
            sortUnique();
            sortCount();
            printColumns();

            break;
        }
        case fileIn: {

            cout << "Enter file directory/name: ";
            cin >> fUserIn;

            ifs.open(fUserIn);

            if (ifs.fail()) {
                cout << "Unable to open file\n";
                exit(1);
            }

            size = 0;
            ifs >> inputArr[size];

            while (!ifs.eof()) {
                size++;
                ifs >> inputArr[size];
            }
            ifs.close();

            selectSort();
            sortUnique();
            sortCount();
            printColumns();

            break;
        }
    }
    return 0;
}

void sortUnique() {
    
    int last = 1;
    intArr[0][0] = inputArr[0];

    for (int k = 1; k < size; k++) {
        if (inputArr[k-1] > inputArr[k]) {
            intArr[last][0] = inputArr[k]; 
            last++;
            numUnique++;
        }
    }
}

void selectSort() {
    cout << "\nYou entered (Unsorted): ";
    for (int z = 0; z < size; z++)
        cout << inputArr[z] << " ";
    cout <<"\n";

    int numIdx; //sort big to small
    int temp;
    for (int j = 0; j < size-1; j++) {
        numIdx = j;
        for (int i = j+1; i < size; i++) {
            if (inputArr[i] > inputArr[numIdx])
                numIdx = i;
        }
        temp = inputArr[j];
        inputArr[j] = inputArr[numIdx];
        inputArr[numIdx] = temp;
    }
}

void sortCount() { 

    int lastIdx = 0;
    for (int m = 0; m < size; m++) {
        intArr[m][1] = 0;
    }
    for (int n = 0; n < size; n++) {
        if (inputArr[n] != intArr[lastIdx][0])
            lastIdx++;
        intArr[lastIdx][1]++;
    }
}

void printColumns() {
    cout << "You entered (Sorted): ";

    for (int z = 0; z < size; z++)
        cout << inputArr[z] << " ";
    cout <<"\n";

    cout << left << setw(colWidth) << setfill(spacer) << fixed << "N";
    cout << left << setw(colWidth) << setfill(spacer) << fixed << "Count" << endl;

    for (int x = 0; x < numUnique; x++) {
        for (int y = 0; y < 2; y++)
            cout << left << setw(colWidth) << setfill(spacer) << fixed << intArr[x][y];
        cout << "\n";
    }
}

/**
 * Algorithm for Exercise 2:
 1. Store kb or file input into int array inputArr[50], split paths with switch statement
 2. If file, use ifs to open file. Close after storing file input into inputArr
 3. Perform selection sort on inputArr to arrange numbers from greatest to least
 4. inputArr will be from greatest to least, so iterate until a number smaller than
    indexed is found and add it to separate 2d array intArr
 5. inputArr will be from greatest to least, so iterate until a number smaller than
    indexed is found, while iterating the respective intArr row in the 2nd column
 6. Print columns

 * Pseudocode
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define kbIn 0
#define fileIn 1
#define colWidth 5
const char spacer = ' ';
ifstream ifs;
ofstream ofs;
int size = 0;
int numUnique = 0;
int inputArr[50], intArr[50][2], userIn;
char fUserIn[50];
void sortUnique();
void selectSort();
void sortCount();
void printColumns();
int main() {
   //Ask for user input and store into userIn to match appropriate switch case
    switch (userIn){
        case kbIn: { //If user wants KB

            //Ask user for number list and store in inputArr[size];

            while (inputArr[size] != 0) {
                size++;
                cin >> inputArr[size];
            } 
            selectSort();
            sortUnique();
            sortCount();
            printColumns();
            break;
        }
        case fileIn: { //If user wants file in

            cout << "Enter file directory/name: ";
            cin >> fUserIn;

            ifs.open(fUserIn);

            if (ifs.fail()) {
                cout << "Unable to open file\n";
                exit(1);
            }

            size = 0;
            ifs >> inputArr[size];

            while (!ifs.eof()) {
                size++;
                ifs >> inputArr[size];
            }
            cout << "\n Size: " << size << "\n";

            ifs.close(); //Close file
            selectSort();
            sortUnique();
            sortCount();
            printColumns();
            break;
        }
    }
    return 0;
}
void sortUnique() {
    int last = 1; //index to denote 
    intArr[0][0] = inputArr[0];
    for (int k = 1; k < size; k++) {
        if (inputArr[k-1] > inputArr[k]) {
            //Set column 0, row last of intArr to new found smaller value and increment
              last
        }
    }
}
void selectSort() {
    int numIdx; //sort from big to small
    int temp;
    for (int j = 0; j < size-1; j++) {
        numIdx = j; //Set numIdx to j to freshly sort, ignore already sorted indexes
        for (int i = j+1; i < size; i++) {
            if (inputArr[i] > inputArr[numIdx])
                //Set numIdx to i if new inputArr value is greater than older one
        }
        //Swap inputArr[j] and inputArr[numIdx]
    }
}
void sortCount() { 
    int lastIdx = 0;
    //Initialize 2nd column of intArr to 0
    for (int n = 0; n < size; n++) {
        if (inputArr[n] != intArr[lastIdx][0])
            //Iterate lastIdx
        //Increment column 2, row lastIdx of intArr
            
    }
}
void printColumns() {
    //Print by iteration
}

 * Output of Lab Exercise 2:
*Output 1 (KB):
Would you like to input integers through keyboard(0) or file(1)? 0
Enter up to 50 numbers (ctrl+d[unix] or ctrl+z[win] to terminate and add a space to the last char): 3 5 1 -5 1 -7 80 -48 
You entered (Unsorted): 3 5 1 -5 1 -7 80 -48 
You entered (Sorted): 80 5 3 1 1 -5 -7 -48 
N    Count
80   1    
5    1    
3    1    
1    2    
-5   1    
-7   1    
-48  1  

*Output 2 (File):
Would you like to input integers through keyboard(0) or file(1)? 1
Enter file directory/name: LabInput3-2.txt

You entered (Unsorted): -3 4 1 1 3 4 0 
You entered (Sorted): 4 4 3 1 1 0 -3 
N    Count
4    2    
3    1    
1    2    
0    1    
-3   1    

**/

//g++ -o Lab3_2.exe Lab3_2.cpp
//./Lab3_2.exe
//LabInput3-2.txt