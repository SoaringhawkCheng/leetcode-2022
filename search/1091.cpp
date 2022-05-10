//
// Created by 成翔昊 on 2022/5/10.
//

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        if (grid.empty()) {
            return -1;
        }

        int row = grid.size(), col = grid[0].size();
        queue<pair<int, int>> q;
        if (grid[0][0] != 0 || grid[row - 1][col - 1] != 0) {
            return -1;
        }

        vector<vector<int>> directs = {{-1, 0},
                                       {1,  0},
                                       {0,  -1},
                                       {0,  1},
                                       {-1, -1},
                                       {-1, 1},
                                       {1,  -1},
                                       {1,  1}};

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> path(row, vector<int>(col, -1));
        q.push(make_pair(0, 0));
        visited[0][0] = true;
        path[0][0] = 1;

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            for (auto direct: directs) {
                pair<int, int> next = make_pair(curr.first + direct[0], curr.second + direct[1]);
                if (next.first >= 0 && next.first < row && next.second >= 0 && next.second < col &&
                    !visited[next.first][next.second] && grid[next.first][next.second] == 0) {
                    visited[next.first][next.second] = true;
                    q.push(make_pair(next.first, next.second));
                    path[next.first][next.second] = path[curr.first][curr.second] + 1;
                }
            }
        }

        return path[row - 1][col - 1];
    }
};

int main() {
    vector<vector<int>> grid = {{0, 0, 0, 0, 1},
                                {1, 0, 0, 0, 0},
                                {0, 1, 0, 1, 0},
                                {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 0}};
    Solution s;
    cout << s.shortestPathBinaryMatrix(grid) << endl;
}