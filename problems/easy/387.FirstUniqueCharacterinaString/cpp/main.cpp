#include <unordered_map>
#include <string>

/*
    Problem statement:
    Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
*/

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char,int> m;
    for(int i=0; i<s.size();i++) m[s[i]]++;
    for(int i=0; i<s.size();i++) if(m[s[i]]==1) return i;
    return -1;
    
}


int main(){

    return 0;
}