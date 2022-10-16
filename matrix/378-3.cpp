//
// Created by 成翔昊 on 2022/10/15.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return -1;

        int row = matrix.size(), col = matrix[0].size();
        int low = matrix[0][0], high = matrix[row - 1][col - 1];

        while (low < high) {
            int mid = low + (high - low)/2;
            int cnt = 0;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col && matrix[i][j] <= mid; j++) {
                    cnt++;
                }
            }

            if (cnt < k) low = mid + 1;
            else high = mid;
        }

        return low;
    }
};