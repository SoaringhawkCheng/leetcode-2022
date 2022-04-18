//
// Created by 成翔昊 on 2022/4/18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool wordExists;
    vector<pair<int, int>> directs;
    vector<vector<bool>> visited;
public:
    Solution() {
        wordExists = false;
        directs = {{-1, 0},
                   {1,  0},
                   {0,  -1},
                   {0,  1}};
    };

    bool exist(vector<vector<char>> &board, string word) {// 多起点dfs
        if (board.empty() || board[0].empty() || word.empty()) {
            return false;
        }

        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j]=true;
                    dfs(board, word, 0, make_pair(i, j));
                    visited[i][j]=false;
                    if (wordExists) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    void dfs(const vector<vector<char>> &board, const string &word, int index, pair<int, int> pos) {
        if (index == word.size() - 1) {
            wordExists = true;
            return;
        }

        for (auto direct: directs) {
            pair<int, int> newPos = calcPos(board, pos, direct);
            if (checkPos(board, word, index + 1, newPos)) {
                visited[newPos.first][newPos.second] = true;
                dfs(board, word, index + 1, newPos);
                visited[newPos.first][newPos.second] = false;
                if (wordExists) {
                    return;
                }
            }
        }
    }

    pair<int, int> calcPos(const vector<vector<char>> &board, pair<int, int> pos, pair<int, int> direct) {
        return make_pair(pos.first + direct.first, pos.second + direct.second);
    }

    bool checkPos(const vector<vector<char>> &board, const string &word, int index, pair<int, int> &pos) {
        if (pos.first < 0 || pos.first >= board.size()) {
            return false;
        }
        if (pos.second < 0 || pos.second >= board[0].size()) {
            return false;
        }
        if (visited[pos.first][pos.second]) {
            return false;
        }

        return board[pos.first][pos.second] == word[index];
    }
};

int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};

    Solution s;
    cout << s.exist(board, "ABCCED") << endl;
}