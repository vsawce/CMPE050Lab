/**
 * Lab 3_3
 * Vincent Saw
 * CMPE50
 **/
#include <iostream>
#include <fstream>

using namespace std;

ifstream ifs1;
ifstream ifs2;
ofstream ofs;
char input1[] = "LabInput3-3.txt";
char input2[] = "LabInput3-4.txt";
char output[] = "LabOutput3-Ex3.txt";
int file1[100];
int file2[100];
int outFile[200];
int size1 = 0;
int size2 = 0;
int sizeO;

void selectSort();
void combineFiles(ifstream& i1, ifstream& i2, ofstream& o);

int main() {
    ifs1.open(input1);
    if(ifs1.fail()) {
        cout << "Could not open " << input1 << endl;
        exit(1);
    }

    ifs2.open(input2);
    if(ifs2.fail()) {
        cout << "Could not open " << input2 << endl;
        exit(1);
    }

    ofs.open(output);
    if(ofs.fail()) {
        cout << "Could not open " << output << endl;
        exit(1);
    }

    combineFiles(ifs1,ifs2,ofs);

    return 0;
}

void selectSort() {

    int numIdx; //sort big to small
    int temp;
    for (int x = 0; x < sizeO-1; x++) {
        numIdx = x;
        for (int y = x+1; y < sizeO; y++) {
            if (outFile[y] < outFile[numIdx])
                numIdx = y;
        }
        temp = outFile[x];
        outFile[x] = outFile[numIdx];
        outFile[numIdx] = temp;
    }

    cout << "\nSorted Output File: ";
    for (int z = 0; z < sizeO; z++)
    cout << outFile[z] << " ";
}

void combineFiles(ifstream& i1, ifstream& i2, ofstream& o) {

    size1 = 0;
    while (i1 >> file1[size1])
        size1++;
    cout << "File 1: ";
    for (int i = 0; i < size1; i++)
        cout << file1[i] << " ";
    i1.close();

    size2 = 0;
    while (i2 >> file2[size2])
        size2++;
    cout << "\nFile 2: ";
    for (int j = 0; j < size2; j++)
        cout << file2[j] << " ";
    i2.close();

    cout <<"\n";

    sizeO = size1 + size2;
    for (int k = 0; k < size1; k++)
       outFile[k] = file1[k];
    for (int l = size1; l < sizeO; l++)
       outFile[l] = file2[l-size1];

    cout << "Unsorted Output File: ";
    for (int m = 0; m < sizeO; m++)
        cout << outFile[m] << " ";

    selectSort();

    for (int n = 0; n < sizeO; n++)
        o << outFile[n] << " ";
    cout << "\nFile exported to \"" << output << "\" in the same directory.\n";
    o.close();
}

/**
 * Algorithm for Exercise 3:
 1. Declare two integer arrays file1[] and file2[], and one integer array twice the size outFile
    (for the output). 
 2. Initialize 2 size integers size1 and size2 to 0. Declare 1 more size integer sizeO for total size
 3. Declare 2 ifstream objects and 1 ofstream object
 4. Open all 3 fstream objects to the appropriate file name
 5. Pass 3 fstream objects to a function designed for combining files
 6. In the function, iterate with condition being the inserting of i1 into file1[size1]. Essentially eof. In the body increment size1.
 7. Repeat for i2 with respective array and size variable
 8. Set sizeO to size1+size2
 9. Iterate from 0 to size1, copying over file1 to outFile
 10. Iterate from size1 to sizeO, copying over file2 to outFile
 11. Call a selection sort from smallest to greatest on outFile
 12. Iterate from 0 to n to extract outFile[n] to an external file


 * Pseudocode
#include <iostream>
#include <fstream>
using namespace std;
ifstream ifs1;
ifstream ifs2;
ofstream ofs;
char input1[] = "LabInput3-3.txt";
char input2[] = "LabInput3-4.txt";
char output[] = "LabOutput3-Ex3";
int file1[100];
int file2[100];
int outFile[200];
int size1 = 0;
int size2 = 0;
int sizeO;
void selectSort();
void combineFiles(ifstream& i1, ifstream& i2, ofstream& o);
int main() {
    ifs1.open(input1);
    //ifs1 open fail detect

    ifs2.open(input2);
    //ifs2 open fail detect

    ofs.open(output);
    //ifs2 open fail detect

    combineFiles(ifs1,ifs2,ofs);

    return 0;
}
void selectSort() {
    int numIdx; //sort big to small
    int temp;
    for (int x = 0; x < sizeO-1; x++) {
        //set numIdx to x to skip already sorted indexes
        for (int y = x+1; y < sizeO; y++) {
            if (outFile[y] < outFile[numIdx])
                //Set numIdx to i if new outFile[y] value is smaller than older one
        }
        //swap outFile[x] and outFile[numIdx] values;
    }
}
void combineFiles(ifstream& i1, ifstream& i2, ofstream& o) {
    size1 = 0;
    while (i1 >> file1[size1]) //Iterate until eof
        size1++;
    i1.close();

    size2 = 0;
    while (i2 >> file2[size2]) //Iterate until eof
        size2++;
    i2.close();

    //Combine files
    sizeO = size1 + size2;
    for (int k = 0; k < size1; k++)
       outFile[k] = file1[k];
    for (int l = size1; l < sizeO; l++)
       outFile[l] = file2[l-size1];

    selectSort(); //Call selectSort function here

    for (int n = 0; n < sizeO; n++)
        //Extract outFile[n] to o
    o.close();
}

 * Output of Lab Exercise 3:
File 1: 6 10 15 22 33 77 88 99 
File 2: 30 40 50 60 62 89 
Unsorted Output File: 6 10 15 22 33 77 88 99 30 40 50 60 62 89 
Sorted Output File: 6 10 15 22 30 33 40 50 60 62 77 88 89 99 
File exported to "LabOutput3-Ex3.txt" in the same directory.

**/

//g++ -o Lab3_3.exe Lab3_3.cpp
//./Lab3_3.exe
//LabInput3-3.txt
//LabInput3-4.txt