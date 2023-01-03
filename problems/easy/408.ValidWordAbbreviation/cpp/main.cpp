#include <iostream>
#include <string>
/*
    Problem statement:
    A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.

    For example, a string such as "substitution" could be abbreviated as (but not limited to):

    "s10n" ("s ubstitutio n")
    "sub4u4" ("sub stit u tion")
    "12" ("substitution")
    "su3i1u2on" ("su bst i t u ti on")
    "substitution" (no substrings replaced)
    The following are not valid abbreviations:

    "s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
    "s010n" (has leading zeros)
    "s0ubstitution" (replaces an empty substring)
    Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.

    A substring is a contiguous non-empty sequence of characters within a string.
*/
using namespace std;

bool validWordAbbreviation(string word, string abbr) {
    int i = 0, j = 0;
    for(i = 0; i<abbr.size();i++){
        string go;
        while(isdigit(abbr[i])){
            go+=abbr[i++];
        }
        if(go.size()>0 && go[0]=='0') return false;
        int offSet = (go.size()==0) ? 0 : stoi(go);
        j+=offSet;
        if(i==abbr.size()&&j==word.size())
            return true;
        if(j>word.size())
            return false;
        if(j<word.size() && i<abbr.size()&&word[j]!=abbr[i])
            return false;
        j++;
    }
    return i==abbr.size()&&j==word.size();
}

int main() {
    string w1 = "internationalization"; 
    string a1= "i12iz4n";
    string w2 = "apple"; 
    string a2 = "a2e";

    cout << "My answer for validWordAbbreviation(w1,a1) = " << validWordAbbreviation(w1,a1) << " and the right answer is 1" << endl;
    cout << "My answer for validWordAbbreviation(w2,a2) = " << validWordAbbreviation(w2,a1) << " and the right answer is 0" << endl;
    return 0;
}