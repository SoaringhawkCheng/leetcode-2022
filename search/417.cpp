//
// Created by 成翔昊 on 2022/5/10.
//

#include <vector>

using namespace std;

class Solution {
private:
    int row, col;
    vector<pair<int, int>> directs;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        vector<vector<int>> res;
        if (heights.empty() || heights[0].empty()) {
            return res;
        }

        row = heights.size(), col = heights[0].size();
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));
        directs = {{-1, 0},
                   {1,  0},
                   {0,  -1},
                   {0,  1}};

        for (int i = 0; i < row; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, col - 1);
        }
        for (int j = 0; j < col; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, row - 1, j);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

private:
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int x, int y) {
        if (x < 0 || x >= row || y < 0 || y >= col || visited[x][y]) return;
        visited[x][y] = true;
        for (auto direct: directs) {
            int next_x = x + direct.first;
            int next_y = y + direct.second;
            if (next_x < 0 || next_x >= row || next_y < 0 || next_y >= col) continue;
            if (heights[next_x][next_y] >= heights[x][y]) dfs(heights, visited, next_x, next_y);
        }
    }
};