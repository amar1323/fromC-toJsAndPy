#include <iostream>
#include <vector>
#include <cmath>
/*
    Problem statement
    The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
    Given an integer n, return the number of distinct solutions to the n-queens puzzle.
*/
using namespace std;

bool isGoodQueenPlacement(int i, int j, int iQ, int jQ){
    if( i == iQ) return false;
    if( j == jQ) return false;
    if( abs(i-iQ) == abs(j-jQ)) return false;
    return true;
}

void helper(int n, int i, vector<int>& queens, int& ret){
    if(i==n){
        ret++;
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
            helper(n,i+1, queens, ret);
        }
    }
}

int totalNQueens(int n) {
    vector<int> queens(n);
    int ret = 0;
    helper(n,0,queens,ret);
    return ret;
}

int main(){
    cout << "expected solution of nQueens(8) is :  92  my solution is" << totalNQueens(8)<<endl; 
    return 0;
}