#include <iostream>
#include <string>
/*
    Problem statement:
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
    Given a string s, return true if it is a palindrome, or false otherwise.
*/
using namespace std;

bool isPalindrome1(string s) {
    auto r =remove_if(s.begin(),s.end(), [](char c){return !isalnum(c);});
    s.erase(r,s.end());
    transform(s.begin(),s.end(),s.begin(), [](char c){return tolower(c);});
    string sR(s.rbegin(),s.rend());
    return s==sR;
}

bool isPalindrome(string s) {
    for(int i=0, j=s.size()-1; i<j; i++,j--){
        while(!isalnum(s[i]) && i<j) i++;
        while(!isalnum(s[j]) && i<j) j--;
        if(tolower(s[i])!=tolower(s[j]))
            return false;
    }
    return true;
}

int main() {
    string in1 = "A man, a plan, a canal: Panama";
    string in2 = "race a car";
    string in3 = " ";
    cout << "My answer for isPalindrome(in1) = "  << isPalindrome(in1) << " and the right answer is 1" << endl;
    cout << "My answer for isPalindrome(in2) = "  << isPalindrome(in2) << " and the right answer is 0" << endl;
    cout << "My answer for isPalindrome(in3) = "  << isPalindrome(in3) << " and the right answer is 1" << endl;
    return 0;
}