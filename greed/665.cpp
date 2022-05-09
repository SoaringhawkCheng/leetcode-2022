//
// Created by 成翔昊 on 2022/5/9.
//

#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
                if (count > 1) return false;
                bool left = false, right = false;
                if (i == 0 || nums[i - 1] <= nums[i + 1]) left = true;
                if (i + 2 >= nums.size() || nums[i] <= nums[i + 2]) right = true;
                if (!left && !right) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 7, 1, 8};
    s.checkPossibility(nums);
}