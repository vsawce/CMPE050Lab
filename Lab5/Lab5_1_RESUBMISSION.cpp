/**
 * Lab 5_1
 * Vincent Saw
 * CMPE50
 * g++ -o Lab5_1.exe Lab5_1.cpp
 * ./Lab5_1.exe
**/

#include <iostream>
#include <iomanip>

using namespace std;

class Student {
    private:
        double quiz1, quiz2, midtermExam, finalExam, average;
    public:
        Student (){ //Default constructor, must be public
            quiz1 = 0;
            quiz2 = 0;
            midtermExam = 0;
            finalExam = 0;
            average = 0;
            cout << "Student Constructor\n";
        }
        void SetQuiz1(double q1); //out of 10pts
        void SetQuiz2(double q2); //out of 10pts
        void SetMidtermExam(double mt); //out of 100pts
        void SetFinalExam(double fnl); //out of 100pts
        void CalculateAverage();
        double GetQuiz1(), GetQuiz2(), GetMidtermExam(), GetFinalExam(), GetAverage();
};

int main() {
    Student s1;
    s1.SetQuiz1(9.205);
    s1.SetMidtermExam(40);
    s1.SetFinalExam(98.44);

    cout << "Quiz 1: " << fixed << setprecision(2) << s1.GetQuiz1() <<
    "\nQuiz 2: " << fixed << setprecision(2) << s1.GetQuiz2() << 
    "\nMidterm: " << fixed << setprecision(2) << s1.GetMidtermExam() <<
    "\nFinal: " << fixed << setprecision(2) << s1.GetFinalExam();

    s1.CalculateAverage(); //Should print average and set average var of s1

    cout <<"\nAverage VARIABLE: " << fixed << setprecision(2) << s1.GetAverage() << endl;
    return 0;
}

void Student::CalculateAverage() {
    average = ( (.25*(quiz1+quiz2)/20) + (.25*midtermExam/100) + (.5*finalExam/100)) * 100; //Calc local var avg
    cout << "\nAverage score (Calc. Avg Member Func.): " << setprecision(2) << fixed << average; //Print member var average
}

void Student::SetQuiz1(double q1) { //double parameter is mutator
    if (q1 <= 10 && q1 >= 0)
        quiz1 = q1;
    else
        cout << "\nQuiz 1 score out of range! (0 to 10 pts).";
    } 
void Student::SetQuiz2(double q2) { //double parameter is mutator
    if (q2 <= 10 && q2 >= 0)
        quiz2 = q2;
    else
        cout << "\nQuiz 2 score out of range! (0 to 10 pts).";
} 
void Student::SetMidtermExam(double mt) { //double parameter is mutator
    if (mt <= 100 && mt >= 0)
        midtermExam = mt;
    else
        cout << "\nMidterm score out of range! (0 to 100 pts).";
    } 
void Student::SetFinalExam(double fnl) { //double parameter is mutator 
    if (fnl <= 100 && fnl >= 0)
        finalExam = fnl;
    else 
        cout << "\nFinal score out of range! (0 to 100 pts).";
    } 
double Student::GetQuiz1() { return quiz1; } //accessor
double Student::GetQuiz2() { return quiz2; } //accessor
double Student::GetMidtermExam() { return midtermExam; } //accessor
double Student::GetFinalExam() { return finalExam; } //accessor
double Student::GetAverage() { return average; } //accessor




/**
****************** Algorithm ******************
For class Student:
    1. Declare all member variables as private;
    2. For public, create Student constructor that sets
    all member vars to 0. Also define all functions
For Student::CalculateAverage():
    1. Set member function average equal to the appropraite
    calculation
For Student::set(double d):
    1. Set respective quiz/exam member function to argument d
For Student::get():
    1. Return respective quiz/exam member function

***************** Pseudocode ******************
class Student {
    private: //Directly unaccesible by main
        double quiz1, quiz2, midtermExam, finalExam, average;
    public: //Directly accessible by main
        Student (){ //Default constructor, must be public
            //Set all member vars to 0
            cout << "Student Constructor\n";
        }
        void SetQuiz1(double q1); //out of 10pts
        void SetQuiz2(double q2); //out of 10pts
        void SetMidtermExam(double mt); //out of 100pts
        void SetFinalExam(double fnl); //out of 100pts
        void CalculateAverage();
        double GetQuiz1(), GetQuiz2(), GetMidtermExam(), GetFinalExam(), GetAverage();
};
int main() {
    Student s1;
    s1.SetQuiz1(9.205);
    s1.SetMidtermExam(40);
    s1.SetFinalExam(98.44);
    cout << //All quiz and test scores with s1.getXYZ(double abc);
    s1.CalculateAverage(); //Should print average and set average var of s1
    cout <<"\nAverage VARIABLE: " << fixed << setprecision(2) << s1.GetAverage() << endl;
    return 0;
}
void Student::CalculateAverage() {
    average = //Calc local var avg
    //Print member var average
}
void Student::SetQuiz1(double q1) { //Set member var quiz1 to val of arg q1 } //double parameter is mutator
void Student::SetQuiz2(double q2) { //Set member var quiz2 to val of arg q2 } //double parameter is mutator
void Student::SetMidtermExam(double mt) { //Set member var midtermExam to val of arg mt } //double parameter is mutator
void Student::SetFinalExam(double fnl) { //Set member var finalExam to val of arg fnl } //double parameter is mutator 
double Student::GetQuiz1() { //return member var quiz1 } //accessor
double Student::GetQuiz2() { //return member var quiz2 } //accessor
double Student::GetMidtermExam() { //return member var midtermExam } //accessor
double Student::GetFinalExam() { //return member var finalExam } //accessor
double Student::GetAverage() { //return member var average; } //accessor

*********** Output of Lab Exercise ************
Student Constructor
Quiz 1: 9.21
Quiz 2: 0.00
Midterm: 40.00
Final: 98.44
Average score (Calc. Avg Member Func.): 70.73
Average VARIABLE: 70.73

**/