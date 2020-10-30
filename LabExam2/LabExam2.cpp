/**
 * LabExam2
 * Vincent Saw
 * CMPE50
 * g++ -o LabExam2.exe LabExam2.cpp
 * ./LabExam2.exe
**/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string num[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

/********** Question 3 **********/
class Diner {
    private:
        string name, category;
        int rating[5];
        double average;
    public:
        Diner() {
            name = "NO NAME";
            category = "NO CATEGORY";
            for (int i = 0; i < 5; i++) rating[i] = 0;
            average = 0;
        }
        Diner(string nm, string cat) {
            name = nm;
            category = cat;
            for (int i = 0; i < 5; i++) rating[i] = 0;
            average = 0;
        }
        string getName();
        string getCategory();
        int getNumRatingsOf(int r); //r is rating value
        double getAverage();
        void setName(string nm);
        void setCategory(string cat);
        void addRating(int r); //r is rating value
        friend bool compareAverage(Diner& d1, Diner& d2);
};
string Diner::getName(){
    return name;
}
string Diner::getCategory(){
    return category;
}
int Diner::getNumRatingsOf(int r) {
    return rating[r-1];
}
double Diner::getAverage() {
    double sum = 0;
    int entries = 0;
    for (int i = 0; i < 5; i++) {
        sum += (rating[i]*(i+1)); //number of ratings * respective rating value
        entries += rating[i];
    }
    average = sum/entries;
    return average;
}
void Diner::addRating(int r) {
    if (r <= 5 && r >= 1) {
        rating[r-1]++;
    }
    else {
        cout << "***Please enter a valid rating! You entered " << r << "***\n";
    }
}
bool compareAverage(Diner& d1, Diner& d2) {
    if (d1.average == d2.average) return true;
    else return false;
}
/********** Question 2 **********/
void numReplace(ifstream& ifs, ofstream& ofs) {
    string fstr;
    char number;

    cout << "--------------- Altered Output ---------------\n";
    while (getline(ifs, fstr)) {
        //cout << "Before: " << fstr << endl;
        for (int i = 0; i <= 9; i++) { //Number replacement, O(n^2). Shitty run time sorry :(
            number = '0' + i; //Convert i into char
            for (int j = 0; j < fstr.length(); j++) { //Search through entire file
                if (fstr.at(j) == number) { //fstr.at(j) returns char, so needs to be compared to the respective number converted to char
                    fstr.erase(j, 1); //Erase substring of length 1 at index j
                    fstr.insert(j, num[i]); //Insert substring num[i] at index j
                    j += num[i].length(); //Move index j to accomodate for substring num[i]'s length
                }
            }
        }
        //cout << "After: " << fstr << endl;
        cout << fstr << endl;
        ofs << fstr << endl;
        
    }
    cout << "--------------- End Conversion ---------------" << endl;
    cout << "Output sent to console and file.\n" << endl;
}

int main() {
    /********** Question 1 **********/
    int userOption;
    for(;;) {
        cout << "# Would you like to execute ex2(1), ex3(2), or end the program(3)?: ";
        cin >> userOption; 

        if (userOption == 3) {
            break;
        }

        switch(userOption) {
            case 1: { //ex2
                ifstream ifs;
                ofstream ofs;
                ifs.open("input2.txt");
                ofs.open("output2.txt");
                numReplace(ifs, ofs);
                break;
            }
            case 2: { //ex3
                Diner dObj1("Denny's", "American"); //Create 2 diner objects
                Diner dObj2("Sukiya", "Japanese");

                dObj1.addRating(0); //Test 1-5 validation

                dObj1.addRating(2); //Denny's ratings suck, add 5 ratings
                dObj1.addRating(2);
                dObj1.addRating(2);
                dObj1.addRating(3);
                dObj1.addRating(1); //Should equal 2, 2+2+2+3+1/5 = 2

                dObj2.addRating(4); //Sukiya is a better restaurant, add another 5 ratings
                dObj2.addRating(4);
                dObj2.addRating(2);
                dObj2.addRating(4);
                dObj2.addRating(5); //Should equal 3.8, 4+4+2+4+5/5 = 3.8

                cout << "----- Diner 1 -----" <<
                "\nName: " << dObj1.getName() << //Outputs name
                "\nCategory: " << dObj1.getCategory() << //Outputs category
                "\nAverage rating: " << dObj1.getAverage() << //Outputs average rating
                "\nNumber of 5 star ratings: " << dObj1.getNumRatingsOf(5) << endl;

                cout << "----- Diner 2 -----" <<
                "\nName: " << dObj2.getName() << //Outputs name
                "\nCategory: " << dObj2.getCategory() << //Outputs category
                "\nAverage rating: " << dObj2.getAverage() << //Outputs average rating
                "\nNumber of 5 star ratings: " << dObj2.getNumRatingsOf(5);

                cout << "\n----- Diners Compared -----" <<
                "\nAre Diner 1 and Diner 2's averages the same(1) or not(0)?: " << compareAverage(dObj1, dObj2) << endl << endl; //Compare objects

                break;
            }
            default: {
                cout << "Please enter a valid option!\n\n";
                break;
            }
        }
        

    }
    cout << "Program terminated." << endl;
    return 0;
}

/**
*********** Example Output of Lab Exam ************
# Would you like to execute ex2(1), ex3(2), or end the program(3)?: 0
Please enter a valid option!

# Would you like to execute ex2(1), ex3(2), or end the program(3)?: 1
--------------- Altered Output ---------------
The price of the cup is four dollars. But it's on sale today at two for six dollars.

If you buy more, you can get three for eight dollars.
--------------- End Conversion ---------------
Output sent to console and file.

# Would you like to execute ex2(1), ex3(2), or end the program(3)?: 2
***Please enter a valid rating! You entered 0***
----- Diner 1 -----
Name: Denny's
Category: American
Average rating: 2
Number of 5 star ratings: 0
----- Diner 2 -----
Name: Sukiya
Category: Japanese
Average rating: 3.8
Number of 5 star ratings: 1
----- Diners Compared -----
Are Diner 1 and Diner 2's averages the same(1) or not(0)?: 0

# Would you like to execute ex2(1), ex3(2), or end the program(3)?: 3
Program terminated.

**/