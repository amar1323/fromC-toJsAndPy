#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

/*
    Problem statement
    Given a list of words, list of  single letters (might be repeating) and score of every character.
    Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).
    It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively 
*/
using namespace std;

void helper(vector<string>& words, unordered_map<char, int>& formableW, vector<int>& score, int idx, int localS, int& ret) {
    ret = max(ret, localS);
    for (int i = idx; i < words.size(); i++) {
        string& currS = words[i];
        unordered_map<char, int> saveFormableW = formableW;
        int saveLocal = localS;
        bool ok = true;
        for (auto c : currS) {
            formableW[c]--;
            if (formableW[c] < 0) {
                ok = false;
                break;
            }
            localS += score[c - 'a'];
        }
        if (ok) {
            helper(words, formableW, score, i + 1, localS, ret);
        }
        formableW = saveFormableW;
        localS = saveLocal;
    }
}
int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    unordered_map<char, int> formableW;
    int ret = 0;
    for (auto c : letters)
        formableW[c]++;
    helper(words, formableW, score, 0, 0, ret);
    return ret;
}

int main() {
    vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vector<int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};

    cout << " Reference solution of maxScoreWords(words,letters,score) = 23 and my solution is: "<< maxScoreWords(words,letters,score)<<endl;

    return 0;
}