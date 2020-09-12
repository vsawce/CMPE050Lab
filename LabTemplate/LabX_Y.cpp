/**
 * Lab X_Y
 * Vincent Saw
 * CMPE50
 * g++ -o LabX_Y.exe LabX_Y.cpp
 * ./LabX_Y.exe
**/

#include <chrono>
#include <iostream>

using namespace std;

int main() {
    auto start = chrono::steady_clock::now();




    auto totalTime = chrono::steady_clock::now() - start;
    cout << "\nTime elapsed: " << chrono::duration <double, milli> (totalTime).count() << "ms\n";
    return 0;
}


/**
 * Algorithm:


 * Pseudocode:


 * Output of Lab Exercise:


**/