//
// Created by 成翔昊 on 2022/2/26.
//

#include "matrix.h"

class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        stack<int> stk;
        int result = 0;

        if (arr.empty()) {
            return result;
        }

        stk.push(arr[0]);
        for (auto i = 1; i < arr.size(); i++) {
            int top = stk.top();
            if (arr[i] >= top) {
                result++;
                while (!stk.empty()) stk.pop();
            }
            stk.push(arr[i]);
        }
        if (!stk.empty()) {
            result++;
        }

        return result;
    }
};

//int main() {
//    Solution s;
//    vector<int> nums = {1, 0, 2, 3, 4};
//    cout << s.maxChunksToSorted(nums) << endl;
//}