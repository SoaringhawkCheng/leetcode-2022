//
// Created by 成翔昊 on 2022/2/26.
//

#include "matrix.h"

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return true;
        }

        int row = matrix.size(), col = matrix[0].size();

        // x=0
        for (int y = 0; y < col; y++) {
            int i = 0, j = y;
            int num = matrix[i][j];
            while (i + 1 < row && j + 1 < col) {
                i++, j++;
                if (matrix[i][j] != num) return false;
            }
        }

        // y=0
        for (int x = 1; x < row; x++) {
            int i = x, j = 0;
            int num = matrix[i][j];
            while (i + 1 < row && j + 1 < col) {
                i++, j++;
                if (matrix[i][j] != num) return false;
            }
        }

        return true;
    }
};

//int main() {
//    vector<vector<int>> nums = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
//    Solution s;
//    cout << s.isToeplitzMatrix(nums) << endl;
//}