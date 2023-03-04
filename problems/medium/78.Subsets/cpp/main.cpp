#include <vector>

using namespace std;
/*
    Problem statement
    Given an integer array nums of unique elements, return all possible 
    subsets(the power set).
    The solution set must not contain duplicate subsets. Return the solution in any order.
*/
void helper(vector<int>& nums, vector<int>& sub, int idx,vector<vector<int>>& ret ){
    ret.push_back(sub);
    for(int i=idx; i<nums.size();i++){
        sub.push_back(nums[i]);
        helper(nums, sub, i+1, ret);
        sub.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> sub;
    vector<vector<int>> ret;
    helper(nums,sub,0,ret);
    return ret;
}

int main(){


    return 0;
}