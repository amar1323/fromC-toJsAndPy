#include <vector>
#include <iostream>

/*
    Problem statement
    Write a program to solve a Sudoku puzzle by filling the empty cells.
    A sudoku solution must satisfy all of the following rules:
    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
    The '.' character indicates empty cells.
*/
using namespace std;

vector<vector<bool>> colum= vector<vector<bool>>(9, vector<bool>(9,false));
vector<vector<bool>> line = vector<vector<bool>>(9, vector<bool>(9,false));
vector<vector<bool>> block =vector<vector<bool>>(9, vector<bool>(9,false));

bool backtrack(vector<vector<char>>& board, int curr, vector<pair<int,int>>& toSolve){
    if(curr >= toSolve.size())
        return true;
    for(int  n= 0; n<9; n++){
        int i = toSolve[curr].first, j = toSolve[curr].second;
        int k = k = (i/3)*3+j/3;
        if(!line[i][n] && !colum[j][n] && !block[k][n]){
            line[i][n] = colum[j][n]= block[k][n] = true;
            board[toSolve[curr].first][toSolve[curr].second] = '1'+n;
            if(backtrack(board,curr+1, toSolve))
                return true;
            line[i][n] = colum[j][n]= block[k][n] = false;
            board[toSolve[curr].first][toSolve[curr].second] = '.';
        }

    }
    return false;
}
void solveSudoku(vector<vector<char>>& board) {
    vector<pair<int,int>> toSolve;
    for(int i=0; i<9;i++){
        for(int j=0; j<9;j++){
            if(board[i][j] =='.'){
                toSolve.push_back(make_pair(i,j));
            } else{
                char cur =board[i][j];
                if(cur=='.') continue;
                int k = (i/3)*3+j/3;
                line[i][cur-'1'] = colum[j][cur-'1']= block[k][cur-'1'] = true;
            }
        }
    }
    backtrack(board,0,toSolve);    
}


int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
                                
    solveSudoku(board);

    for(auto& vC : board){
        for(auto c : vC){
            cout<< c<<"   ";
        }
        cout<<endl;
    }

    return 0;
}