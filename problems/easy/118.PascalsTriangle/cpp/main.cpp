#include <vector>
/*
    Problem statement:
    Given an integer numRows, return the first numRows of Pascal's triangle.
*/
using namespace std;

vector<vector<int>> generatePascal(int numRows) {
    vector<vector<int>> ret(numRows);
    for(int i =0; i<numRows;i++){
        ret[i] = vector<int>(i+1,1);
    }
    for(int i =2; i< ret.size();i++){
        for(int j = 1; j<ret[i].size()-1; j++)
            ret[i][j]=ret[i-1][j-1]+ret[i-1][j];
    }
    return ret;
}

int main(){

    return 0;
}