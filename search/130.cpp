//
// Created by 成翔昊 on 2022/5/10.
//

#include <vector>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> directs;
    int row, col;
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        row = board.size(), col = board[0].size();
        directs = {{-1, 0},
                   {1,  0},
                   {0,  -1},
                   {0,  1}};


        for (int i = 0; i < row; i++) {
            dfs(board, make_pair(i, 0));
            dfs(board, make_pair(i, col - 1));
        }
        for (int j = 0; j < col; j++) {
            dfs(board, make_pair(0, j));
            dfs(board, make_pair(row - 1, j));
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'T') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }

    }

private:
    void dfs(vector<vector<char>> &board, pair<int, int> pos) {
        if (pos.first < 0 || pos.first >= row || pos.second < 0 || pos.second >= col ||
            board[pos.first][pos.second] != 'O')
            return;

        board[pos.first][pos.second] = 'T';
        for (auto direct: directs) {
            dfs(board, make_pair(pos.first + direct.first, pos.second + direct.second));
        }
    }
};