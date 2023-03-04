#include <iostream>
#include <vector>

using namespace std;

void crush(vector<vector<int>>& board, vector<vector<bool>>& toCrush, int i, int j, pair<int, int> dir, int& num) {
    //if (toCrush[i][j]) return;
    int in = i + dir.first;
    int jn = j + dir.second;
    if (in >= board.size()) return;
    if (jn >= board[in].size()) return;
    if (board[i][j] == board[in][jn]) {
        num++;
        if (num == 2) {
            toCrush[in - dir.first][jn - dir.second] = true;
            toCrush[in - 2 * dir.first][jn - 2 * dir.second] = true;
        }
        if(num >=2)
            toCrush[in][jn] = true;
        crush(board, toCrush, in, jn, dir, num);
    }
}

vector<vector<int>> candyCrush(vector<vector<int>>& board) {
    bool hasMoved = false;
    pair<int, int> left = make_pair(0, 1);
    pair<int, int> down = make_pair(1, 0);
    cout << "--------------------start all--------------------------" << endl;
    for (int i = 0; i < board.size(); i++) {  // crush all
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << "   ";
        }
        cout << endl;
    }

    do {
        hasMoved = false;
        vector<vector<bool>> toCrush(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {  // select to cruch all
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 0) continue;
                int num = 0;
                crush(board, toCrush, i, j, left, num);
                if (num >= 2) hasMoved = true;
                num = 0;
                crush(board, toCrush, i, j, down, num);
                if (num >= 2) hasMoved = true;
            }
        }
        cout << "--------------------before crush all--------------------------" << endl;
        for (int i = 0; i < board.size(); i++) {  // crush all
            for (int j = 0; j < board[i].size(); j++) {
                if (toCrush[i][j])
                    board[i][j] = 0;
                cout << board[i][j] << "   ";
            }
            cout << endl;
        }
        cout << "-------------------- after crush all--------------------------" << endl;

        for (int j = 0; j < board[0].size(); j++) {
            int k = board.size() - 1;
            for (int i = board.size() - 1; i >= 0; i--) {
                if (board[i][j] != 0)
                    swap(board[i][j], board[k--][j]);
            }
        }
        for (int i = 0; i < board.size(); i++) {  // crush all
            for (int j = 0; j < board[i].size(); j++) {
                cout << board[i][j] << "   ";
            }
            cout << endl;
        }
        cout << "--------------------after zeros all--------------------------" << endl;

    } while (hasMoved == true);
    return board;
}

int main() {
    vector<vector<int>> in1 = {{110, 5, 112, 113, 114}, {210, 211, 5, 213, 214}, {310, 311, 3, 313, 314}, {410, 411, 412, 5, 414}, {5, 1, 512, 3, 3}, {610, 4, 1, 613, 614}, {710, 1, 2, 713, 714}, {810, 1, 2, 1, 1}, {1, 1, 2, 2, 2}, {4, 1, 4, 4, 1014}};
    vector<vector<int>> in2 = {{1,3,5,5,2},{3,4,3,3,1},{3,2,4,5,2},{2,4,4,5,5},{1,4,4,1,1}};
    //auto ans2 = candyCrush(in2);
    auto ans1 = candyCrush(in1);
}