//
// Created by 成翔昊 on 2022/5/10.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int row, col, size;
    vector<vector<bool>> visited;
    vector<pair<int, int>> directs;
    bool wordExists;
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (word.empty() || board.empty() || board[0].empty()) return false;
        size = word.size(), row = board.size(), col = board[0].size();
        wordExists = false;
        visited = vector<vector<bool>>(row, vector<bool>(col, false));
        directs = {{-1, 0},
                   {1,  0},
                   {0,  -1},
                   {0,  1}};

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dfs(board, word, i, j, 0);
                if (wordExists) return true;
            }
        }
        return false;
    }

private:
    void dfs(vector<vector<char>> &board, string &word, int x, int y, int step) {
        if (step == size) {
            wordExists = true;
            return;
        }

        if (x < 0 || x >= row || y < 0 || y >= col || visited[x][y] || board[x][y] != word[step]) return;

        visited[x][y] = true;
        for (auto direct: directs) {
            int next_x = x + direct.first, next_y = y + direct.second;
            dfs(board, word, next_x, next_y, step + 1);
            if (wordExists) return;
        }
        visited[x][y] = false;
    }
};