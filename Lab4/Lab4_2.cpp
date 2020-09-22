/**
 * Lab 4_2
 * Vincent Saw
 * CMPE50
 * g++ -o Lab4_2.exe Lab4_2.cpp
 * ./Lab4_2.exe
**/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string str;
string he = "he";
string she = "she";
string her = "her";
string him = "him";
string hers = "her(s)";
string his = "his";
string shehe = "she or he";
string herhim = "her or him";
string hershis = "her(s) or his";
int i;

int main() {
    while(str != "done") {
        cout << "Enter sentence (type \"done\" when done): ";
        getline(cin, str);
        i = 0;
        string sStr;
        /*Could have checked all of this with a for loop and arrays, sorry.*/
        while(1) { 
            sStr = str.substr(i);
            if (str.substr(i,hers.length()) == hers) {
                str.erase(i,hers.length());
                str.insert(i, hershis);
                i = i+hershis.length();
                continue;
            }
            else if (str.substr(i,his.length()) == his) {
                str.erase(i,his.length());
                str.insert(i, hershis);
                i = i+hershis.length();
                continue;
            }
            else if (str.substr(i,her.length()) == her) {
                str.erase(i,her.length());
                str.insert(i, herhim);
                i = i+herhim.length();
                continue;
            }
            else if (str.substr(i,him.length()) == him) {
                str.erase(i,him.length());
                str.insert(i, herhim);
                i = i+herhim.length();
                continue;
            }
            else if (str.substr(i,he.length()) == he) {
                str.erase(i,he.length());
                str.insert(i, shehe);
                i = i+shehe.length();
                continue;
            }
            else if (str.substr(i,she.length()) == she) {
                str.erase(i,she.length());
                str.insert(i, shehe);
                i = i+shehe.length();
                continue;
            }
            else if (!(sStr.empty())) {
                i++;
                continue;
            }
            break;
        }
        cout << str << "\n";

    }

    return 0;
}

/**
 * Algorithm:
1. Declare string str and assign string variables to all 6 words to be replaced with
2. Store user input to str with getline for string variables.
3. Set int i iterator to 0
4. In a while loop, check for each word using substring and the comparison word's length
5. If word found, erase substring of str from i, with length being the comparison word's length.
    Then insert appropriate string at index i.
    Then add the length of inserted string to i.
    Finally, continue.
6. If str substring with pos i isn't empty, increment i and continue
7. At the end of the while loop, break. Break should not occur until str.substr(i) is empty,
    meaning the entire string has been searched.

 * Pseudocode:
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string str;
string he = "he";
string she = "she";
string her = "her";
string him = "him";
string hers = "her(s)";
string his = "his";
string shehe = "she or he";
string herhim = "her or him";
string hershis = "her(s) or his";
int i;

int main() {
    while(str != "done")
        cout << "Enter sentence (type \"done\" when done): ";
        getline(cin, str, '\n');
        i = 0;
        string sStr;
        while(1) { 
            sStr = str.substr(i);
            if (str.substr(i,hers.length()) == hers) {
                //Erase str.substr from index i with len of compared string
                //Insert appropriate string at index i
                //Move index i to after the inserted string
                continue;
            }
            else if (str.substr(i,his.length()) == his) {
                //Erase str.substr from index i with len of compared string
                //Insert appropriate string at index i
                //Move index i to after the inserted string
                continue;
            }
            else if (str.substr(i,her.length()) == her) {
                //Erase str.substr from index i with len of compared string
                //Insert appropriate string at index i
                //Move index i to after the inserted string
                continue;
            }
            else if (str.substr(i,him.length()) == him) {
                //Erase str.substr from index i with len of compared string
                //Insert appropriate string at index i
                //Move index i to after the inserted string
                continue;
            }
            else if (str.substr(i,he.length()) == he) {
                //Erase str.substr from index i with len of compared string
                //Insert appropriate string at index i
                //Move index i to after the inserted string
                continue;
            }
            else if (str.substr(i,she.length()) == she) {
                //Erase str.substr from index i with len of compared string
                //Insert appropriate string at index i
                //Move index i to after the inserted string
                continue;
            }
            else if (!(sStr.empty())) { //If str isn't empty
                i++;
                continue;
            }
            break;
        }
        cout << str << "\n";
    }
    return 0;
}

 * Output of Lab Exercise:
Enter sentence (type "done" when done): See an adviser, talk to him, and listen to him.
See an adviser, talk to her or him, and listen to her or him.
Enter sentence (type "done" when done): See an adviser, talk to he, and listen to she. 
See an adviser, talk to she or he, and listen to she or he.
Enter sentence (type "done" when done): See an adviser, talk to her(s), and listen to his. 
See an adviser, talk to her(s) or his, and listen to her(s) or his.
Enter sentence (type "done" when done): done
done
**/