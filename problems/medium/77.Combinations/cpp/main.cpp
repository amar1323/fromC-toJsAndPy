#include <vector>

using namespace std;
/*
    Problem statement
    Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
    You may return the answer in any order.
*/

void helper(int k, int n, int idx, vector<int> sub, vector<vector<int>>& ret){
    if(sub.size()> k )
        return;
    else if(sub.size()==k){
        ret.push_back(sub);
        return;
    }
    for(int i = idx; i<=n;i++){
        sub.push_back(i);
        helper(k,n,i+1,sub,ret);
        sub.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<int> sub;
    vector<vector<int>> ret;
    helper(k,n, 1,sub,ret);
    return ret;
}

int main(){

    return 0;
}