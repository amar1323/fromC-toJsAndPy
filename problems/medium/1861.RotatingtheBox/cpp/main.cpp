#include <vector>

using namespace std;
/*
    Problem statement:
    You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:
    A stone '#'
    A stationary obstacle '*'
    Empty '.'
    The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

    It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

    Return an n x m matrix representing the box after the rotation described above.
*/

void move(vector<vector<char>>& box, int colum, int s, int e) {
    int k = e;
    for (int i = e; i >= s; i--) {
        if (box[i][colum] != '.') {
            swap(box[i][colum], box[k--][colum]);
        }
    }
}
vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    vector<vector<char>> ret(box[0].size(), vector<char>(box.size()));
    vector<vector<int>> obst(box.size());
    int inv = box.size()-1;
    for (int i = 0; i < box.size(); i++) {
        obst[inv-i].push_back(0);
        for (int j = 0; j < box[i].size(); j++) {
            ret[j][inv-i] = box[i][j];
            if (box[i][j] == '*'){
                obst[inv-i].push_back(j-1);
                obst[inv-i].push_back(j+1);
            }
        }
        obst[inv-i].push_back(box[i].size() - 1);
    }
    for (int j = 0; j < ret[0].size(); j++) {
        for (int b = 0; b < obst[j].size() - 1; b+=2) {
            if(obst[j][b]==obst[j][b+1]) continue;
            move(ret, j, obst[j][b], obst[j][b + 1]);
        }
    }
    return ret;
}


int main(){

    return 0;
}