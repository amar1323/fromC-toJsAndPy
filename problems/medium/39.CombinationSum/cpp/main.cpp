#include <vector>

using namespace std;
/*
    Problem statement
    Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

    The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.

    The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/



void helper(vector<int>& candidates,int idx, vector<int> sub, int curr, int target, vector<vector<int>>& ret){
    if(curr> target)
        return;
    else if(curr==target){
        ret.push_back(sub);
        return;
    }
    for(int i=idx; i<candidates.size();i++){
        sub.push_back(candidates[i]);
        curr+=candidates[i];
        helper(candidates,i, sub, curr, target, ret);
        sub.pop_back();
        curr-=candidates[i];
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ret;
    int curr = 0;
    vector<int> sub;
    helper(candidates,0,sub,curr,target,ret);
    return vector<vector<int>>(ret.begin(),ret.end());
}

int main(){

    return 0;
}