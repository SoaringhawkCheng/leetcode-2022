//
// Created by 成翔昊 on 2022/2/26.
//

#include "matrix.h"

class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        int degree = 0, degreeLen = 0;
        unordered_map<int, int> count, firstPos;
        for (int i = 0; i < nums.size(); i++) {
            if (firstPos.find(nums[i]) == firstPos.end()) {
                count[nums[i]] = 1;
                firstPos[nums[i]] = i;
            } else {
                count[nums[i]]++;
            }

            if (count[nums[i]] > degree) {
                degree = count[nums[i]];
                degreeLen = i - firstPos[nums[i]] + 1;
            } else if (count[nums[i]] == degree) {
                int len = i - firstPos[nums[i]] + 1;
                if (len < degreeLen) {
                    degreeLen = len;
                }
            }
        }

        return degreeLen;
    }
};

//int main() {
//    Solution s;
//    vector<int> nums = {2, 1, 1, 2, 1, 3, 3, 3, 1, 3, 1, 3, 2};
//    cout << s.findShortestSubArray(nums) << endl;
//}