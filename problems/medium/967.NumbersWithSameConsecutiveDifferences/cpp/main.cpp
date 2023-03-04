#include <vector>
#include <string>

using namespace std;
/*
    Problem statement
    Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.
    Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.
*/
void helper(int n, int k, string sub, vector<int>& ret){
    if(sub.size()==n){
        int toAdd = -1;
        try{
            toAdd=stoi(sub);
        }catch(std::out_of_range& e){
        }
        if(toAdd>0) ret.push_back(toAdd);
        return;
    }
    int last = sub.back()-'0';
    if(last-k>=0)
        helper(n,k,sub+to_string(last-k),ret);
    if(last+k<=9 && k!=0)
        helper(n,k,sub+to_string(last+k),ret);

}
vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> ret;
    for(int i=1; i<10; i++){
        helper(n,k,to_string(i),ret);
    }
    return ret;
}
int main(){

    return 0;
}