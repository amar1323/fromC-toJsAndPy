#include <iostream>
#include <utility>
#include <vector>
/*
    Problem statement
    You are given an m x n integer array grid where grid[i][j] could be:
    1 representing the starting square. There is exactly one starting square.
    2 representing the ending square. There is exactly one ending square.
    0 representing empty squares we can walk over.
    -1 representing obstacles that we cannot walk over.
    Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.
*/

using namespace std;
int numberWalkables = 0;
vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void backtrack(vector<vector<int>>& grid, pair<int, int> current, vector<vector<bool>>& visited, int& ret, int traversed) {
    if (current.first < 0 || current.second < 0 || current.first >= grid.size() || current.second >= grid[0].size()) return;
    if (visited[current.first][current.second] || grid[current.first][current.second] == -1) return;
    if (grid[current.first][current.second] == 2 && traversed == numberWalkables) {
        ret++;
        return;
    }
    visited[current.first][current.second] = true;
    for (auto& d : dirs) {
        backtrack(grid, make_pair(current.first + d.first, current.second + d.second), visited, ret, traversed + 1);
    }
    visited[current.first][current.second] = false;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    int ret = 0;
    pair<int, int> start;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1) start = make_pair(i, j);
            if (grid[i][j] >= 0) numberWalkables++;
        }
    }
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    backtrack(grid, start, visited, ret, 1);
    return ret;
}
int main() {
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};
    auto ans = uniquePathsIII(grid);
    cout << " Reference solution of uniquePathsIII(grid) = 4 and my solution is: " << ans << endl;
    return 0;
}