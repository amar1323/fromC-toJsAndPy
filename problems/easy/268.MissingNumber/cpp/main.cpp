#include <vector>
#include <numeric>
#include <iostream>
/*
    Problem statement:
    Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
*/
using namespace std;

int missingNumber(vector<int>& nums) {
    int sumWithout = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    return n*(n+1)/2-sumWithout;
}


int main(){
    vector<int> in1 = {3,0,1};
    cout << "My answer for missingNumber(in1) = " <<  missingNumber(in1)  << " and the right answer is 2" << endl;
    return 0;
}


