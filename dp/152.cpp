//
// Created by 成翔昊 on 2022/7/2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // f1[i]表示以i为结尾的连续数组的最大值
    // f2[i]表示以i为结尾的连续数组的最小值
    // f1[i+1] = max(f1[i]*nums[i+1], f2[i]*nums[i+1], nums[i+1])
    // f2[i+1] = min(f1[i]*nums[i+1], f2[i]*nums[i+1], nums[i+1])
    int maxProduct(vector<int> &nums) {
        if (nums.empty()) return 0;

        int fMax = nums[0], fMin = nums[0], res = nums[0];
        cout << "num fMax fMin res" << endl;
        for (int i = 1; i < nums.size(); i++) {
            int fMaxPrev = fMax, fMinPrev = fMin;
            fMax = max(nums[i], max(fMaxPrev * nums[i], fMinPrev * nums[i]));
            fMin = min(nums[i], min(fMaxPrev * nums[i], fMinPrev * nums[i]));
            res = max(res, fMax);
            cout << nums[i] << ": " << fMax << " " << fMin << " " << res << endl;
        }

        return res;
    }
};

int main() {
    vector<int> nums = {-4, -3, -2};
    Solution s;
    cout << s.maxProduct(nums) << endl;
}