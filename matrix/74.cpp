//
// Created by 成翔昊 on 2022/7/6.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int col = matrix.size(), row = matrix[0].size();
        int begin = 0, end = col * row;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            int num = matrix[mid / row][mid % row];
            if (num == target) return true;
            else if (num < target) begin = mid + 1;
            else end = mid;
        }

        return false;
    }
};