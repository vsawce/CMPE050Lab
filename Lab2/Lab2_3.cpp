/**
 * Lab 2_3
 * Vincent Saw
 * CMPE50
 **/

#include <iostream>
#include <iomanip>

using namespace std;

#define sets 5
#define rows 2

const char spacer = ' ';
const int nameWidth = 5;
const int numWidth = 7;

char rowNames[rows][20] = {"HW","LAB"};
double passingGrade[rows] = {50, 50};
double setArr[sets][rows]; //last index for AVG
double avgArr[sets];

void storeUserInput();
void printColumn();
void printHwLabRow(); 
void printAvgRow();
void printOverall();
void checkPass();
double getBest(int rowIndex);
double getWorst(int rowIndex);
double getAvg(int rowIndex);
double getOverall();


int main() {

    storeUserInput();

    printColumn();

    printHwLabRow();

    printAvgRow();

    printOverall();

    checkPass();

    return 0;
}

void storeUserInput() {
    double hw, set;

    for (int i = 0; i < sets; i++) {
        cout << "Enter set " << i+1 << " HW and Lab Exam score seperated by a space: ";
        cin >> hw;
        setArr[i][0] = hw;
        cin >> set;
        setArr[i][1] = set;
    }
    cout << "\n";
}

void printColumn() {
    cout << left << setw(nameWidth) << setfill(spacer) << "SET";

    for (int x = 1; x <= sets; x++)
        cout << left << setw(numWidth) << setfill(spacer) << x;

    cout << left << setw(numWidth) << setfill(spacer) << "BEST";
    cout << left << setw(numWidth) << setfill(spacer) << "WORST";
    cout << left << setw(numWidth) << setfill(spacer) << "AVG";

    cout << "\n" << left << setw(nameWidth) << setfill(spacer) << " ";
    
    for (int y = 0; y < ((3+sets)*(numWidth)); y++)
        cout << "*";

    cout << "\n";
}

void printHwLabRow() {

    for (int j = 0; j < rows; j++) { //j = 0 HW row, j = 1 Lab row

        cout << left << setw(nameWidth) << setfill(spacer) << rowNames[j];

        for (int k = 0; k < sets; k++)
            cout << left << setw(numWidth) << setfill(spacer) << fixed << setprecision(2) << setArr[k][j];
        
        cout << left << setw(numWidth) << setfill(spacer) << fixed << setprecision(2) << getBest(j); 
        cout << left << setw(numWidth) << setfill(spacer) << fixed << setprecision(2) << getWorst(j);
        cout << left << setw(numWidth) << setfill(spacer) << fixed << setprecision(2) << getAvg(j) << "\n";
    }
}

void printAvgRow() {
    cout << "\n" << left << setw(nameWidth) << setfill(spacer) << "AVG";

    for (int l = 0; l < sets; l++) {
        for (int m = 0; m < rows; m++) {
            avgArr[l] += setArr[l][m];
        }
        avgArr[l] /= rows;

        cout << left << setw(numWidth) << setfill(spacer) << fixed << setprecision(2) << avgArr[l];
    }
}

void printOverall() {
    cout << "  Overall: " << getOverall() << "%" << endl;
}

void checkPass() {
    bool pass = true;

    for (int n = 0; n < rows; n++) {
        if (getAvg(n) < passingGrade[n]) {
            pass = false;
            cout << "\n\nI'm happy to inform you that you failed the class, because your performance in the "
             << rowNames[n] << " category was <" << passingGrade[n] << "%. Try again never!" << endl;
            break;
        }
    }
    if (pass)
        cout << "\n\nCongratulations! You passed the class!" << endl;
}

double getBest(int rowIndex) {
    double best = setArr[0][rowIndex];

    for (int a = 1; a < sets; a++) {
        if (setArr[a][rowIndex] > best)
            best = setArr[a][rowIndex];
    }

    return best;
}

double getWorst(int rowIndex) {
    double worst = setArr[0][rowIndex];

    for (int b = 1; b < sets; b++) {
        if (setArr[b][rowIndex] < worst)
            worst = setArr[b][rowIndex];
    }

    return worst;
}

double getAvg(int rowIndex) {
    double avg = 0;
    for (int c = 0; c < sets; c++) {
        avg += setArr[c][rowIndex];
    }

    avg /= sets;

    return avg;
}

double getOverall() {
    double overall;

    for (int d = 0; d < rows; d++) {
        for (int e = 0; e < sets; e++) {
            overall += setArr[e][d];
        }
    }

    overall /= (sets*rows);

    return overall;
}


/**
 * Algorithm for Exercise 3 key code:
1. Declare a 2D array setArr[5][2] to store both HW and LAB scores, and create 1D array avgArr[5] for the combined average scores
2. Store user input into setArr
3. getBest(): Loop 5 times to find best score var best (sort for largest value with temporary variable) of given index (0 = HW, 1 = LAB), return best
4. getWorst(): Loop 5 times to find worst score var worst (sort for smallest value with temporary variable) of given index (0 = HW, 1 = LAB), return worst
5. getAvg(): Nested for loop, add every value in setArr to one variable avg and divide avg by total amount of sets (5) in setArr, return avg
6. Calculate average of column n by averaging values of setArr[n][0] and setArr[n][1] and store to avgArr[n]
7. Print out values for HW row with setArr[x][0] where x = 0-4 and also call getBest(0), getWorst(0), getAvg(0)
8. Print out values for LAB row with setArr[x][1] where x = 0-4 and also call getBest(1), getWorst(1), getAvg(1)
9. getOverall(): Nested for loop to add every single value of the 2D array setArr to double var overall, divide var overall by amount of values (sets*rows), return overall
10. Print out values of avgArr[x] where x = 0-4 and also print getOverall() by calling it in cout
11. checkPass(): Check if avg score per row is below passing grade (50) and if below, say the student failed in the respective category. If avg score per row isn't below, then say the student passed.

 * Pseudocode of key code
#include <iostream>
#include <iomanip>
using namespace std;

#define sets 5
#define rows 2
const char spacer = ' ';
const int nameWidth = 5;
const int numWidth = 7;
char rowNames[rows][20] = {"HW","LAB"};
double passingGrade[rows] = {50, 50};
double setArr[sets][rows]; //last index for AVG
double avgArr[sets];
void storeUserInput();
void printColumn();
void printHwLabRow(); 
void printAvgRow();
void printOverall();
void checkPass();
double getBest(int rowIndex);
double getWorst(int rowIndex);
double getAvg(int rowIndex);
double getOverall();

int main() {
    storeUserInput();
    printColumn();
    printHwLabRow();
    printAvgRow();
    printOverall();
    checkPass();
    return 0;
}

void checkPass() {
    bool pass = true; //Flag variable

    for (int n = 0; n < rows; n++) { //Iterate per row, starting at HW (0)
        if (getAvg(n) < passingGrade[n]) { //As soon as any failing grade found by calling getAvg(n) for the respective row, flag pass as false, print fail statement, break loop and terminate.
            pass = false;
            cout << "\n\nI'm happy to inform you that you failed the class, because your performance in the "
             << rowNames[n] << " category was <" << passingGrade[n] << "%. Try again never!" << endl;
            break;
        }
    }
    if (pass) //if flag unaltered, means no failing grade found. Student passed.
        cout << "\n\nCongratulations! You passed the class!" << endl;
}

double getBest(int rowIndex) {
    double best = setArr[0][rowIndex]; //Store 1st var as default, skip 1 iteration

    for (int a = 1; a < sets; a++) {
        if (setArr[a][rowIndex] > best) //if new variable found in setArr is bigger than old variable stored in best, replace best's value with setArr[a][rowIndex]'s value.
            best = setArr[a][rowIndex];
    }

    return best;
}

double getWorst(int rowIndex) {
    double worst = setArr[0][rowIndex]; //Store 1st var as default, skip 1 iteration

    for (int b = 1; b < sets; b++) {
        if (setArr[b][rowIndex] < worst) //if new variable found in setArr is smaller than old variable stored in worst, replace worst's value with setArr[b][rowIndex]'s value.
            worst = setArr[b][rowIndex];
    }

    return worst;
}

double getAvg(int rowIndex) {
    double avg = 0;

    //Loop through one row of setArr to get total value for the row
    for (int c = 0; c < sets; c++) {
        avg += setArr[c][rowIndex];
    }
    avg /= sets; //Divide total value of row by amount of columns to get avg
    return avg;
}

double getOverall() {
    double overall;

    //Nested loop to get total value of setArr
    for (int d = 0; d < rows; d++) {
        for (int e = 0; e < sets; e++) {
            overall += setArr[e][d];
        }
    }
    overall /= (sets*rows); //Divide total value of setArr by rows*columns to get avg
    return overall;
}



 * Output 1 of Lab Exercise 3:
Enter set 1 HW and Lab Exam score seperated by a space: 100 100
Enter set 2 HW and Lab Exam score seperated by a space: 90 100
Enter set 3 HW and Lab Exam score seperated by a space: 80 70
Enter set 4 HW and Lab Exam score seperated by a space: 100 60
Enter set 5 HW and Lab Exam score seperated by a space: 100 90

SET  1      2      3      4      5      BEST   WORST  AVG    
     ********************************************************
HW   100.00 90.00  80.00  100.00 100.00 100.00 80.00  94.00  
LAB  100.00 100.00 70.00  60.00  90.00  100.00 60.00  84.00  

AVG  100.00 95.00  75.00  80.00  95.00    Overall: 89.00%


Congratulations! You passed the class!

 * Output 2 of Lab Exercise 3:
Enter set 1 HW and Lab Exam score seperated by a space: 10 100
Enter set 2 HW and Lab Exam score seperated by a space: 20 100
Enter set 3 HW and Lab Exam score seperated by a space: 30 70
Enter set 4 HW and Lab Exam score seperated by a space: 40 60
Enter set 5 HW and Lab Exam score seperated by a space: 50 90

SET  1      2      3      4      5      BEST   WORST  AVG    
     ********************************************************
HW   10.00  20.00  30.00  40.00  50.00  50.00  10.00  30.00  
LAB  100.00 100.00 70.00  60.00  90.00  100.00 60.00  84.00  

AVG  55.00  60.00  50.00  50.00  70.00    Overall: 57.00%


I'm happy to inform you that you failed the class, because your performance in the HW category was <50.00%. Try again never!

* Output 3 of Lab Exercise 3:
Enter set 1 HW and Lab Exam score seperated by a space: 100 10
Enter set 2 HW and Lab Exam score seperated by a space: 90 20
Enter set 3 HW and Lab Exam score seperated by a space: 80 30
Enter set 4 HW and Lab Exam score seperated by a space: 70 40
Enter set 5 HW and Lab Exam score seperated by a space: 100 50

SET  1      2      3      4      5      BEST   WORST  AVG    
     ********************************************************
HW   100.00 90.00  80.00  70.00  100.00 100.00 70.00  88.00  
LAB  10.00  20.00  30.00  40.00  50.00  50.00  10.00  30.00  

AVG  55.00  55.00  55.00  55.00  75.00    Overall: 59.00%


I'm happy to inform you that you failed the class, because your performance in the LAB category was <50.00%. Try again never!

**/

//g++ -o Lab2_3.exe Lab2_3.cpp
//./Lab2_3.exe