#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

/*
    Problem statement
    You are given a string s and an array of strings words. All the strings of words are of the same length.
    A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.
    For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
    Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.
*/
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    int len = words[0].size();
    vector<int> ret;
    for(int i = 0; i<s.size()-words.size()*len+1;i++){
        unordered_multiset<string> setWords(words.begin(),words.end());
        for(int j = 0; j<words.size();j++){
            string sub = s.substr(i+len*j,len);
            auto it = setWords.find(sub);
            if(it != setWords.end()){
                setWords.erase(it);
            }else 
                break;
        }
        if(setWords.size()==0)
            ret.push_back(i);
    }
    return ret;
}

int main(){
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar","foo","the"};
    auto ans = findSubstring(s,words);
    string out;
    for(auto&  i: ans){
        out+=to_string(i)+",";
    }
    out.pop_back();
    cout << " Reference solution of findSubstring(s,words) = 6,9,12 and my solution is: "<< out<<endl;
    return 0;
}