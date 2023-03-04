#include <vector>

using namespace std;
/*
    Problem statement
    Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

    perm[i] is divisible by i.
    i is divisible by perm[i].
    Given an integer n, return the number of the beautiful arrangements that you can construct.
*/



void helper(vector<int>& in, int& ret, int s, int e){
    if(s==e+1){
        ret++;
    }
    for(int i = s; i<=e;i++){
        swap(in[s], in[i]);
        if(in[s]%(s+1)==0 || (s+1)%in[s]==0 )
            helper(in,ret,s+1,e);
        swap(in[s], in[i]);
    }
}
int countArrangement(int n) {
    vector<int> in(n);
    for(int i=1; i<=n;i++)
        in[i-1]=i;
    int ret=0;
    helper(in,ret,0,in.size()-1);
    return ret;    
}

int main(){

    return 0;
}