//
// Created by 成翔昊 on 2022/5/21.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> roots;
    int row, col, count;
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        row = grid.size(), col = grid[0].size(), count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                roots.push_back(i * col + j);
                if (grid[i][j] == '1') count++;
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '0') continue;
                if (i + 1 < row && grid[i + 1][j] == '1')
                    unite(i * col + j, (i + 1) * col + j);
                if (j + 1 < col && grid[i][j + 1] == '1')
                    unite(i * col + j, i * col + j + 1);
            }
        }

        return count;
    }

private:
    int find(int pos) { // 所有路径上的父节点都设置为根节点
        if (roots[pos] != pos) roots[pos] = find(roots[pos]);
        return roots[pos];
    }

    void unite(int pos1, int pos2) {
        int root1 = find(pos1), root2 = find(pos2);
        if (root1 == root2) return;
        roots[root2] = root1;
        --count;
    }
};

int main() {
    vector<vector<char>> grid = {{'1'},{'1'}};
    Solution s;
    cout << s.numIslands(grid) << endl;
}