//
// Created by 成翔昊 on 2022/10/15.
//

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<char>> grid;
    vector<vector<pair<int, int>>> parent;
    int row, col;
    int cnt = 0;
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        row = grid.size(), col = grid[0].size();
        this->grid = grid;

        parent = vector<vector<pair<int, int>>>(row, vector<pair<int, int>>(col, make_pair(-1, -1)));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '0') continue;

                parent[i][j].first = i;
                parent[i][j].second = j;
                cnt++;
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '0') continue;

                grid[i][j] = '0';
                pair<int, int> center = make_pair(i, j);

                if (validate(i - 1, j)) unite(center, make_pair(i - 1, j));
                if (validate(i + 1, j)) unite(center, make_pair(i + 1, j));
                if (validate(i, j - 1)) unite(center, make_pair(i, j - 1));
                if (validate(i, j + 1)) unite(center, make_pair(i, j + 1));
            }
        }

        return cnt;
    }

private:
    void unite(pair<int, int> center, pair<int, int> adjacent) {
        pair<int, int> rootCenter = find(center);
        pair<int, int> rootAdjacent = find(adjacent);

        if (rootCenter!= rootAdjacent) {
            parent[rootCenter.first][rootCenter.second] = rootAdjacent;
            cnt--;
        }
    }

    pair<int, int> find(pair<int, int> p) {
        if (p != parent[p.first][p.second])
            parent[p.first][p.second] = find(parent[p.first][p.second]);
        return parent[p.first][p.second];
    }


    bool validate(int i, int j) {
        return i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == '1';
    }
};