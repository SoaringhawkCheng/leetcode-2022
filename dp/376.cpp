//
// Created by 成翔昊 on 2022/5/15.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int size = nums.size();
        if (size < 2) return size;

        // up: 以i结尾，最后趋势是up
        // down: 以i结尾，最后趋势是down
        vector<int> ups(size, 1), downs(size, 1);
        int maxLen = 1;
        for (int i = 1; i < size; i++) {
            int up = 1, down = 1;
            for (int j = 0; j < i; j++) {
                down = max(down, downs[j]);
                up = max(up, ups[j]);

                if (nums[j] > nums[i]) {
                    down = max(down, ups[j] + 1);
                } else if (nums[j] < nums[i]) {
                    up = max(up, downs[j] + 1);
                }
            }

            ups[i] = up, downs[i] = down;
            maxLen = max(maxLen, up);
            maxLen = max(maxLen, down);
        }

        return maxLen;
    }
};