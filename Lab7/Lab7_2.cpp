/**
 * Lab 7_2
 * Vincent Saw
 * CMPE50
 * g++ -o Lab7_2.exe Lab7_2.cpp
 * ./Lab7_2.exe
**/

#include <iostream>
#include <cstring>

using namespace std;

char * delete_repeats(char* cStr, int size) {
    char *dArr = new char[size];
    int cnt = 0;
    bool diff;

    for (int i = 0; i < size; i++) {
        diff = 1;
        for (int j = 0; j < i; j++) {
            if (cStr[i] == dArr[j]) {
                diff = 0;
                break;
            }
        }
        if(diff) {
            dArr[cnt] = cStr[i];
            cnt++;
        }
    }

    return dArr;
}

int main() {
    char str[100] = "to be or not to be";
    int size = strlen(str);
    char *noRepeat;
    noRepeat = delete_repeats(str, size);

    cout << noRepeat << endl;

    delete [] noRepeat;

    return 0;
}


/**
****************** Algorithm ******************
1. Create delete_repeats with return type char* (needs to return dynamic character array)
2. Initialize pointer variable, assign to "new" unnamed dynamic character array, same size as input char array
3. Initialize counter to 0 and declare flag variable
4. Iterate through cStr, adding unique characters to dynArr
    a. Iterate from 0 to i, check if current character input[i] equal to any of dynArr's characters
        - If equal, set unique character flag false and break loop
    b. If unique character flag true, assign current character input[i] to dynArr[counter] then increment counter
5. Return dynamic character array
6. Display character array then delete dynamic character array and free memory at the location noRepeat points to
***************** Pseudocode ******************
char * delete_repeats(char* cStr, int size) {
    char *dArr = new char[size]; //Initialize dArr pointer variable to unnamed dynamic character array
    int cnt = 0;
    bool diff;
    for (int i = 0; i < size; i++) { //Iterate through cStr
        diff = 1; //Reset flag
        for (int j = 0; j < i; j++) {
            if (cStr[i] == dArr[j]) { //cStr[i] character matches character in dArr[j]
                diff = 0; //Flag
                break;
            }
        }
        if(diff) { //If current character cStr[i] not in dArr yet
            dArr[cnt] = cStr[i];
            cnt++;
        }
    }
    return dArr; //Return dynamic array
}
int main() {
    char str[100] = "to be or not to be";
    int size = strlen(str);
    char *noRepeat; //Declare pointer variable
    noRepeat = delete_repeats(str, size); //Have variable noRepeat point at dynamic array returned by delete_repeats

    cout << noRepeat << endl;

    delete [] noRepeat; //Delete dynamic character array and free memory at the location noRepeat points to

    return 0;
}
*********** Output of Lab Exercise ************
to bern
**/