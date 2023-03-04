#include <vector>

using namespace std;
/*
    Problem statement
    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

*/

void helper(vector<int>& nums, vector<vector<int>>& ret, int s, int e){
    if(s==e)
        ret.push_back(nums);
    for(int i = s; i<=e;i++){
        swap(nums[s], nums[i]);
        helper(nums,ret,s+1,e);
        swap(nums[s], nums[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ret;
    helper(nums,ret,0,nums.size()-1);
    return ret;
}

int main(){

    return 0;
}