/**
 * Lab 3_1
 * Vincent Saw
 * CMPE50
 **/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {

    ifstream in_stream;
    ofstream out_stream;

    char arr[1000];

    in_stream.open("LabInput3-1.txt");

    if (in_stream.fail()) {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    
    int i = 0;
    while (!in_stream.eof()) {
        in_stream >> arr[i];
        i++;
    }
    in_stream.close();

    for (int j = 0; j < i; j++) {
        arr[j] = toupper(arr[j]);
    }

    out_stream.open("LabOutput3-1.txt");

    if (out_stream.fail()) {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    for (int k = 0; k < i-1; k++) {
        out_stream << arr[k];
    }

    out_stream.close();

    return 0;
}



/**
 * Algorithm for Exercise 1:
 1. Include necessary libraries like iostream, fstream, and cstdlib
 2. Declare character array arr and ifstream ifs/ofstream ofs object
 3. Open given text file with ifs method
 4. Check if file failed to open, exit if error
 5. Design an iterative i while loop with passing condition being while not eof
    Extract character arr[i] to ifs, add 1 to i.
 6. Close ifs
 7. Iterate j from 0 to i of arr and convert the character to upper case using toupper()
 8. Open output file with ofs
 9. Check if file failed to open, exit if error
 10. Iterate k from 0 to i-1 (-1 to skip null char) and insert character arr[k] to ofs, add 1 to k
 11. Close ofs


 * Pseudocode
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {

    ifstream in_stream;
    ofstream out_stream;

    char arr[1000];

    in_stream.open("LabInput3-1.txt");

    if (in_stream.fail()) {
        //print that there's an error and exit
    }
    
    int i = 0;
    while (!in_stream.eof()) {
        //extract arr[i] into in_stream
        //i++
    }
    in_stream.close();

    for (int j = 0; j < i; j++) {
        //assign arr[j] to the toupper() of itself (rewrite arr[j])
    }

    out_stream.open("LabOutput3-1.txt");

    if (out_stream.fail()) {
        //print that there's an error and exit
    }

    for (int k = 0; k < i-1; k++) {
        //insert arr[k] into out_stream
    }

    out_stream.close();

    return 0;
}




 * Output of Lab Exercise 1 in LabOutput3-1.txt:
 THISISASAMPLETESTDATAFILE.

**/

//g++ -o Lab3_1.exe Lab3_1.cpp
//./Lab3_1.exe