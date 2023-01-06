#include <iostream>
#include <vector>
/*
    Problem statement:
    The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

    For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
    Given an array nums, return the sum of all XOR totals for every subset of nums.

    Note: Subsets with the same elements should be counted multiple times.

    An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
*/
using namespace std;

void helper(vector<int>& nums, vector<int>& sub, int idx, int& ret) {
    if (sub.size() > 0) {
        int toAdd = sub[0];
        for (int i = 1; i < sub.size(); i++) {
            toAdd = (toAdd ^ sub[i]);
        }
        ret += toAdd;
    }
    for (int i = idx; i < nums.size(); i++) {
        sub.push_back(nums[i]);
        helper(nums, sub, i + 1, ret);
        sub.pop_back();
    }
}

int subsetXORSum(vector<int>& nums) {
    int ret = 0;
    vector<int> sub;
    helper(nums, sub, 0, ret);
    return ret;
}

int main() {
    vector<int> in1 = {1,3};
    vector<int> in2 = {5,1,6};
    vector<int> in3 = {3,4,5,6,7,8};
    cout << "My answer for subsetXORSum(in1) = " << subsetXORSum(in1) << " and the right answer is 6" << endl;
    cout << "My answer for subsetXORSum(in2) = " << subsetXORSum(in2) << " and the right answer is 28" << endl;
    cout << "My answer for subsetXORSum(in3) = " << subsetXORSum(in3) << " and the right answer is 480" << endl;
    return 0;
}