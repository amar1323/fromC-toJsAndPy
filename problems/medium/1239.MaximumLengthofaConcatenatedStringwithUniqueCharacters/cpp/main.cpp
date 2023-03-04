#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
/*
    Problem statement
    You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

    Return the maximum possible length of s.

    A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

*/
vector<bool> used=vector<bool>(26,false);

void helper(vector<string>& arr,int current, int idx, int& ret ){
    ret=max(ret,current);
    for(int i = idx; i<arr.size();i++){
        string s = arr[i];
        bool to_add = true;
        int count = 0;
        for(auto& c : s){
            if(used[c-'a']){
                to_add = false;
                break;
            }
            count++;
            used[c-'a']= true;
        }
        if(to_add){
            helper(arr,current+s.size(),i+1,ret);
            for(auto& c : s) used[c-'a']=false;
        } else{
            for(int j=0; j<count;j++) used[s[j]-'a'] = false;
        }
    }
}
int maxLength(vector<string>& arr) {
    int ret= -1;
    helper(arr,0,0,ret);
    return ret;
}
int main(){

    return 0;
}