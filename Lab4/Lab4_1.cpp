/**
 * Lab 4_1
 * Vincent Saw
 * CMPE50
 * g++ -o Lab4_1.exe Lab4_1.cpp
 * ./Lab4_1.exe
**/

#include <iostream>
#include <cstring>

#define size 101

using namespace std;

char cStr[size], sortedCStr[size];
int whitespaceCount;

bool IsWhitespace(char ch);

int main() {
    int cnt = 0;
    do {
        cin.get(cStr[cnt]);
        cnt++;
    } while (cStr[cnt-1] != '.' && cnt != size-1);

    cout << "\nUnsorted cStr: ";
    for (int i = 0; i < size; i++)
        cout << cStr[i];
    
    int sortedCount = 0;
    
    for (int i = 0; i < strnlen(cStr, size); i++) {
        whitespaceCount = 0;
        if (IsWhitespace(cStr[i])) {
            while(IsWhitespace(cStr[i+whitespaceCount])) {
                whitespaceCount++;
            } 
            whitespaceCount--;
            sortedCStr[sortedCount] = ' ';
        }
        else {
            sortedCStr[sortedCount] = cStr[i];
        }
        sortedCount++;
        i += whitespaceCount;
    }
    
    cout << "\nWhitespace sorted sortedCStr: \n";
    for (int i = 0; i < strnlen(sortedCStr, size); i++)
        cout << sortedCStr[i];
    
    cout << "\nCompletely sorted sortedCStr: \n";
    sortedCStr[0] = toupper(sortedCStr[0]);
    cout << sortedCStr[0];
    for (int i = 1; i < strnlen(sortedCStr, size); i++) {
        sortedCStr[i] = tolower(sortedCStr[i]);
        cout << sortedCStr[i];
    }
    cout << endl;

    return 0;
}

bool IsWhitespace(char ch) {
    if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
        return true;
    else
        return false;
}

/**
 * Algorithm:
1. Declare char array cStr and sortedCStr to size 100;
2. Declare integer whitespaceCount
3. Store input into cStr using cin.get, with cStr != '.' && size != 101 as condition
4. Write bool return function with char arg IsWhitespace to detect whitespace, return true if whitespace found
5. Initialize sortedCStr to 0
6. If index i of cStr is whitespace, enter while loop that increments whitespaceCount as long as isWhitespace returns true. 
    Decrement whitespaceCount-- for appropriate addition to index for later on. Then set sortedCStr[sortedCount] to a space character
7. Else, store cStr[i] to sortedCStr[sortedCount] and increment sortedCount
8. Set first index/letter of sortedCStr to the toupper of itself and print
9. Starting from 1, increment through sortedCStr, with the body setting index i of sortedCStr to the tolower of itself and print

 * Pseudocode:
#include <iostream>
#include <cstring>
#define size 100
using namespace std;
char cStr[size], sortedCStr[size];
int whitespaceCount;
bool IsWhitespace(char ch);

int main() {

    int cnt = 0;
    do {
        cin.get(cStr[cnt]);
        cnt++;
    } while (cStr[cnt-1] != '.' && cnt != size);

    int sortedCount = 0;
    
    for (int i = 0; i < strnlen(cStr, size); i++) {
        //Reset whitespaceCount to 0
        if (IsWhitespace(cStr[i])) {
            while(IsWhitespace(cStr[i+whitespaceCount])) {
                //Increment whitespaceCount
            } 
            //Decrement whitespaceCount to appropriately add to i later
            //Set index sortedCount of sortedCStr to a space character
        }
        else {
            //Set index sortedCount of sortedCStr to index i of cStr;
        }
        sortedCount++;
        i += whitespaceCount;
    }
    
    //Set first letter of C-String (sortedCStr[0]) to its toupper of itself and print
    for (int i = 1; i < strnlen(sortedCStr, size); i++) {
        //Set sortedCStr[i] to its tolower of itself
        //Print sortedCStr[i]
    }
    cout << endl;

    return 0;
}
bool IsWhitespace(char ch) {
    if (ch == any whitespace char)
        return true;
    else
        return false;
}

 * Output of Lab Exercise:
noW  iS   thE    TiMe  fOr  aLl
         gOOD MEN TO  ComE TO   tHe
                aId
oF


   ThE  CounTRY.

Unsorted cStr: noW  iS   thE    TiMe  fOr  aLl
         gOOD MEN TO  ComE TO   tHe
                aId
oF


   ThE  CounTRY.
Whitespace sorted sortedCStr:
noW iS thE TiMe fOr aLl gOOD MEN TO ComE TO tHe aId oF ThE CounTRY.
Completely sorted sortedCStr:
Now is the time for all good men to come to the aid of the country.
**/