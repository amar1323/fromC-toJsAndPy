#include <iostream>
#include <string>

/*
    Problem statement:
    Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

    You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
*/
using namespace std;

bool isLongPressedName(string name, string typed) {
    if(typed.size()<name.size()) return false;
    int i=0, j=0, kt, kn;
    while(i<name.size() && j<typed.size()){
        kn=i+1;
        int countN=1;
        char c =name[i];
        while(kn < name.size() &&c==name[kn]){
            kn++;
            countN++;
        }
        kt= j;
        int countT=0;
        while(kt < typed.size() && c==typed[kt]){
            kt++;
            countT++;
        }
        if(countT>=countN){
            i=kn;
            j=kt;
        }else
            return false;
    }
    return kt==int(typed.size()) && kn==int(name.size());
}

int main() {
    string in11="alex";
    string in12 ="aaleex";
    string in21 = "saeed";
    string in22 = "ssaaedd";
    cout << "My answer for isLongPressedName(in11,in12) = " << isLongPressedName(in11,in12)  << " and the right answer is 1" << endl;
    cout << "My answer for isLongPressedName(in21,in22) = " << isLongPressedName(in21,in22) << " and the right answer is 0" << endl;

    return 0;
}