//
// Created by 成翔昊 on 2022/10/12.
//

# include "../tree/treenode.h"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
public:
    int getMountain(vector<int> nums) {
        // nums不含边界的0
        auto begin = nums.begin(), end = nums.end();
        while (begin < prev(end)) {
            auto mid = begin + (end - begin) / 2;
            if (*prev(mid) >= *mid) end = mid;
            else begin = mid;
        }

        return begin - nums.begin();
    }
};

int main() {
    vector<int> nums1 = {0, 0, 0, 0};
    vector<int> nums2 = {0, 0, 1, 0, 0};
    Solution s;
    cout << s.getMountain(nums1) << endl;
    cout << s.getMountain(nums2) << endl;
}