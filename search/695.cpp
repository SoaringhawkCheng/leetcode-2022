//
// Created by 成翔昊 on 2022/5/10.
//

#include <vector>

using namespace std;

class Solution {
private:
    int row,col;
    vector<pair<int, int>> directs;
    vector<vector<bool>> visited;
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        row = grid.size(), col = grid[0].size();
        directs = {{-1, 0},
                   {1,  0},
                   {0,  -1},
                   {0,  1}};
        visited = vector<vector<bool>>(row, vector<bool>(col, false));

        int maxArea = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    maxArea = max(maxArea, dfs(grid, make_pair(i, j)));
                }
            }
        }

        return maxArea;
    }

private:
    int dfs(vector<vector<int>> &grid, pair<int, int> pos) {
        int area = 1;
        visited[pos.first][pos.second] = true;

        for (auto direct: directs) {
            pair<int, int> next = make_pair(pos.first + direct.first, pos.second + direct.second);
            if (next.first >= 0 && next.first < row && next.second >= 0 && next.second < col &&
                grid[next.first][next.second] && !visited[next.first][next.second]) {
                area += dfs(grid, next);
            }
        }

        return area;
    }
};

