//
// Created by 成翔昊 on 2022/10/16.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int row, col;
    pair<int, int> root;
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    vector<vector<pair<int, int>>> parent;
    unordered_map<string, int> countMap;
    vector<pair<int, int>> directions = {{-1, 0},
                                         {1,  0},
                                         {0,  -1},
                                         {0,  1}};

public:
    int largestIsland(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        this->grid = grid;
        row = grid.size(), col = grid[0].size();

        visited = vector<vector<bool>>(row, vector<bool>(col));
        parent = vector<vector<pair<int, int>>>(row, vector<pair<int, int>>(col, make_pair(-1, -1)));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (visited[i][j] || grid[i][j] == 0) continue;
                root = make_pair(i, j);
                parent[i][j] = root;
                countMap[getRootKey(root)] = 1;
                dfs(i, j);
            }
        }

        int maxArea = 0;

        for (auto iter = countMap.begin(); iter!=countMap.end(); iter++)
            maxArea = max(maxArea, iter->second);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) continue;
                maxArea = max(maxArea, getArea(i, j));
            }
        }

        return maxArea;
    }

private:
    void dfs(int x, int y) {
        visited[x][y] = true;
        for (auto d: directions) {
            int newX = x + d.first, newY = y + d.second;
            if (validate(newX, newY) && !visited[newX][newY]) {
                parent[newX][newY] = root;
                countMap[getRootKey(root)]++;
                dfs(newX, newY);
            }
        }
    }

    bool validate(int x, int y) {
        return x >= 0 && x < col && y >= 0 && y < row && grid[x][y] == 1;
    }

    string getRootKey(pair<int, int> root) {
        return to_string(root.first) + ":" + to_string(root.second);
    }

    int getArea(int x, int y) {
        unordered_set<string> rootKeySet;
        for (auto d: directions) {
            int newX = x + d.first, newY = y + d.second;
            if (validate(newX, newY))
                rootKeySet.insert(getRootKey(parent[newX][newY]));
        }

        int area = 1;
        for (auto key:rootKeySet) {
            area += countMap[key];
        }

        return area;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{1, 0},
                                {0, 1}};
    cout << s.largestIsland(grid) << endl;
}