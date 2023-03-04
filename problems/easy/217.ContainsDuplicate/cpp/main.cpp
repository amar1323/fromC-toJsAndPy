#include <vector>
#include <unordered_set>
/*
    Problem statement:
    Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for(int i=0; i<nums.size();i++){
        auto it = s.find(nums[i]);
        if(it != s.end()) return true;
        s.insert(nums[i]); 
    }
    return false; 
}

int main(){


    return 0;
}