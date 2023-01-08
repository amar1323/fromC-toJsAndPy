#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

/*
    Problem statement:
    You are given two integer arrays nums1 and nums2 where nums2 is an anagram of nums1. Both arrays may contain duplicates.

    Return an index mapping array mapping from nums1 to nums2 where mapping[i] = j means the ith element in nums1 appears in nums2 at index j. If there are multiple answers, return any of them.

    An array a is an anagram of an array b means b is made by randomizing the order of the elements in a.
*/
using namespace std;

vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,vector<int>> m1;
    unordered_map<int,vector<int>> m2;
    for(int i=0; i<nums1.size();i++){
        m1[nums1[i]].push_back(i);
        m2[nums2[i]].push_back(i);
    }
    vector<int> ret(nums1.size());
    for(int i=0; i<ret.size();i++){
        ret[m1[nums1[i]].back()]=m2[nums1[i]].back();
        m1[nums1[i]].pop_back();
        m2[nums1[i]].pop_back();
    }
    return ret;
}

int main() {
    vector<int> num11 = {12,28,46,32,50};
    vector<int> num12 = {50,12,32,46,28};
    vector<int> num21 = {84,46};
    vector<int> num22 = {84,46};    
    vector<int> ans1 = anagramMappings(num11,num12);
    vector<int> ans2 = anagramMappings(num21,num22);
    string pr1="[",pr2="[";
    for(auto i : ans1) pr1+= to_string(i)+",";
    for(auto i : ans2) pr2+= to_string(i)+",";
    pr1.pop_back();pr1+="]";
    pr2.pop_back();pr2+="]";

    cout << "My answer for anagramMappings(num11,num12) = " << pr1 << " and the right answer is [1,4,3,2,0]" << endl;
    cout << "My answer for anagramMappings(num21,num22) = " << pr2 << " and the right answer is [0,1]" << endl;

    return 0;
}