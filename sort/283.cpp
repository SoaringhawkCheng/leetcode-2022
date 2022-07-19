//
// Created by 成翔昊 on 2022/7/6.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int index = 0; // index前面都是>0
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            int tmp = nums[index];
            nums[index++] = nums[i];
            nums[i] = tmp;
        }
    }
};