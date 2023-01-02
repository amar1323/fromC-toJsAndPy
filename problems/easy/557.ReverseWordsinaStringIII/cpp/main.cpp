#include <iostream>
#include <string>
/*
    Problem statement:
    Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order
*/
using namespace std;

void reverseWord(string& s, int start, int end) {
    while (start < end) swap(s[start++], s[end--]);
}

string reverseWords(string s) {
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            reverseWord(s, j, i - 1);
            j = i + 1;
        }
    }
    if (j < s.size()) reverseWord(s, j, s.size() - 1);

    return s;
}


int main() {
    string in1 ="Let's take LeetCode contest";
    string in2 ="God Ding";

    cout << "My answer for reverseWords(in1) = " << reverseWords(in1) << " and the right answer is s'teL ekat edoCteeL tsetnoc" << endl;
    cout << "My answer for reverseWords(in2) = " << reverseWords(in2) << " and the right answer is doG gniD" << endl;
    return 0;
}