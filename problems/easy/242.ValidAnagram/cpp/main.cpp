#include <string>
#include <unordered_map>

using namespace std;

/*
    Problem statement:
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    unordered_map<char,int> sM;
    unordered_map<char,int> tM;
    for(int i=0; i<s.size();i++){
        sM[s[i]]++;
        tM[t[i]]++;
    }
    return sM==tM;
}

int main(){

    return 0;
}