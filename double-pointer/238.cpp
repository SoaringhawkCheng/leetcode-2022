//
// Created by 成翔昊 on 2022/7/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int size = nums.size();

        vector<int> result(size, 1);
        int prefix = 1, suffix = 1;

        for (int i = 0; i < size; i++) {
            result[i] *= prefix;
            prefix *= nums[i];
        }

        for (int j = 0; j < size; j++) {
            result[size - 1 - j] *= suffix;
            suffix *= nums[size - 1 - j];
        }

        return result;
    }
};