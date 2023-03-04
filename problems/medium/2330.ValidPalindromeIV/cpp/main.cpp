#include <string>

using namespace std;
/*
    Problem statement:

    Check if you can A palindrom by changing 2 characters in a string

*/
bool makePalindrome(string s) {
    int count = 0;
    for(int i=0, j=s.size()-1; i<j; i++,j--){
        if(s[i]!=s[j]){
            count++;
        }
        if(count ==3)
            return false;
    }
    return true;
}

int main(){


    return 0;
}