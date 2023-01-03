#include <iostream>
#include <string>
/*
    Problem statement:
    Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/
using namespace std;

bool checkPalindrom(string s, int m, int n) {
    for (int i = m, j = n; i < j; i++, j--) {
        if (s[i] != s[j])
            return false;
    }
    return true;
}
bool validPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return checkPalindrom(s, i + 1, j) || checkPalindrom(s, i, j - 1);
        }
    }
    return true;
}

int main() {
    cout << "My answer for validPalindrome(\"aba\") = " << validPalindrome("aba") << " and the right answer is 1" << endl;
    cout << "My answer for validPalindrome(\"abca\") = " << validPalindrome("abca") << " and the right answer is 1" << endl;
    cout << "My answer for validPalindrome(\"abc\") = " << validPalindrome("abc") << " and the right answer is 0" << endl;
    return 0;
}