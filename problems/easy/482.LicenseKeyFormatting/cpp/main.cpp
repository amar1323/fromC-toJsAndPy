#include <iostream>
#include <string>


/*
    Problem statement:
    You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.

    We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.

    Return the reformatted license key.
*/
using namespace std;

string licenseKeyFormatting(string s, int k) {
    string ret;
    int l = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '-') continue;
        l++;

        ret += toupper(s[i]);
        if (l == k) {
            l = 0;
            ret += '-';
        }
    }
    if (ret.back() == '-') ret.pop_back();
    return string(ret.rbegin(), ret.rend());
}

int main() {
    string in1 = "5F3Z-2e-9-w";
    string in2 = "2-5g-3-J";

    cout << "My answer for licenseKeyFormatting(in1,4) = " << licenseKeyFormatting(in1,4) << " and the right answer is 5F3Z-2E9W" << endl;
    cout << "My answer for licenseKeyFormatting(in2,2) = " << licenseKeyFormatting(in2,2) << " and the right answer is 2-5G-3J" << endl;
    return 0;
}