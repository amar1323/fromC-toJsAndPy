#include <iostream>
#include <string>
#include <vector>
/*
    Problem statement
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".
*/
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0)
        return "";
    else if (strs.size() == 1)
        return strs[0];
    string ret;
    for (int i = 0; i < strs[0].size(); i++) {
        char c = strs[0][i];
        for (int j = 0; j < strs.size(); j++) {
            if (!(i < strs[j].size() && c == strs[j][i])) return ret;
        }
        ret += c;
    }
    return ret;
}

int main() {
    vector<string> in1 = {"flower","flow","flight"};
    vector<string> in2 = {"dog","racecar","car"};

    cout <<"My answer for longestCommonPrefix(in1)= " << longestCommonPrefix(in1)<< " and real answer is: fl"<<endl;
    cout <<"My answer for longestCommonPrefix(in2)= " << longestCommonPrefix(in2)<< " and real answer is:"<<endl;
    return 0;
}