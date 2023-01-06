#include <iostream>
#include <string>
/*
    Problem statement:
    You are given a string s representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

    'A': Absent.
    'L': Late.
    'P': Present.
    The student is eligible for an attendance award if they meet both of the following criteria:

    The student was absent ('A') for strictly fewer than 2 days total.
    The student was never late ('L') for 3 or more consecutive days.
    Return true if the student is eligible for an attendance award, or false otherwise.
*/
using namespace std;

bool checkRecord(string s) {
    int ab=0;
    int late = 0;
    for(int i=0; i<s.size();i++){
        if(s[i]=='A')  ab++;
        if(ab>=2) return false;
        if(s[i]=='L'){
            while(s[i]=='L'){
                late++;
                i++;
            }
            i--;
        }
        if(late>=3) return false;
        late=0;
    }
    return true;
}

int main() {
    cout << "My answer for checkRecord(\"PPALLP\") = " << checkRecord("PPALLP") << " and the right answer is 1" << endl;
    cout << "My answer for checkRecord(\"PPALLL\") = " << checkRecord("PPALLL") << " and the right answer is 0" << endl;
    return 0;
}