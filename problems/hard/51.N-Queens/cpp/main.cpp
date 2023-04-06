#include <iostream>
#include <vector>
#include <cmath>
/*
    Problem statement
    The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
    Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

using namespace std;

bool isGoodQueenPlacement(int i, int j, int iQ, int jQ){
    if( i == iQ) return false;
    if( j == jQ) return false;
    if( abs(i-iQ) == abs(j-jQ)) return false;
    return true;
}

void helper(int n, int i, vector<int>& queens, vector<string>& currS, vector<vector<string>>& ret){
    if(i==n){
        ret.push_back(currS);
        return;
    }
    for(int j=0; j<n;j++){
        queens[i] =j;
        bool ok = true;
        for(int k = 0; k<i;k++){
            if( !isGoodQueenPlacement(i, j, k, queens[k])){
                ok = false;
                break;
            }
        }
        if(ok){
            currS[i][j]='Q';
            helper(n,i+1, queens, currS, ret);
            currS[i][j]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    string s;
    for(int i=0; i<n;i++) s+='.';
    vector<string> currS(n, s);
    vector<vector<string>> ret;
    vector<int> queens(n);
    helper(n,0,queens,currS, ret);
    return ret;
}

int main(){
    auto solve5 = solveNQueens(5);
    for(auto& vS : solve5){
        for(auto& s: vS){
            cout<< s<<endl;
        }
        cout<<endl;
    }
    return 0;
}