//
// Created by 成翔昊 on 2022/7/6.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // cnt[i]表示集合中<=i的数的个数，
    //  1. 如果只有两个target，那集合中的数从1到n至少有一个，target有两个
    //  2. 如果有更多target，就要把其他数换成target
    // 上述两种情况，都有以下结论：
    //  1. 当i<target的时候， cnt[i]<=i
    //  2. 当i>=target的时候，cnt[i]>i
    int findDuplicate(vector<int> &nums) {
        int begin = 1, end = nums.size();
        int res = -1;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++)
                if (nums[i] <= mid) cnt++;
            if (cnt <= mid) begin = mid + 1;
            else end = res = mid;
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    Solution s;
    cout << s.findDuplicate(nums) << endl;
}