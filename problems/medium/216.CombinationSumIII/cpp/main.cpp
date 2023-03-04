#include <vector>

using namespace std;
/*
    Problem statement
    Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

    Only numbers 1 through 9 are used.
    Each number is used at most once.
    Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/

void helper(int k, int n, int idx,int currSum, vector<int> sub, vector<vector<int>>& ret){
    if(currSum>n || sub.size()> k )
        return;
    else if(currSum == n && sub.size()==k){
        ret.push_back(sub);
        return;
    }
    for(int i = idx; i<10;i++){
        sub.push_back(i);
        currSum+=i;
        helper(k,n,i+1,currSum,sub,ret);
        sub.pop_back();
        currSum-=i;
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> sub;
    vector<vector<int>> ret;
    helper(k,n, 1,0,sub,ret);
    return ret;
}

int main(){

    return 0;
}