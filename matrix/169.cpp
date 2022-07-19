//
// Created by 成翔昊 on 2022/7/2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 一个方法是hashtable，另一个方法是排序，找中位数
    int majorityElement(vector<int> &nums) {
        if (nums.empty()) return -1;
        if (nums.size() <= 2) return nums[0];
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    Solution s;
    cout << s.majorityElement(nums) << endl;
}