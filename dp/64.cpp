//
// Created by 成翔昊 on 2022/2/16.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size()==0||grid[0].size()==0) {
            return 0;
        }
        return minPathSum(grid, grid.size()-1, grid[0].size()-1);
    }

    int minPathSum(vector<vector<int>>& grid, int x, int y) {
        if (x==0 && y==0) {
            return grid[x][y];
        }

        if (x==0) {
            return grid[x][y] + minPathSum(grid, x, y-1);
        }

        if (y==0) {
            return grid[x][y] + minPathSum(grid, x-1, y);
        }

        int minPath = min(grid[x][y] + minPathSum(grid, x-1, y), grid[x][y] + minPathSum(grid, x, y-1));
        cout << x << " " << y << " " << minPath << endl;
        return minPath;
    }
};

//int main() {
//    Solution s = Solution();
//    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
//    cout << s.minPathSum(grid) << endl;
//}