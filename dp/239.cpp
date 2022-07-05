//
// Created by 成翔昊 on 2022/7/4.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    // 维护一个递减序列，保存从大到小的元素的下标
    // 每滑动一次窗口，删除队尾比新元素小的数，同时清除队头不在窗口中的数据
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        deque<int> q;

        // 初始化第一个窗口
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        vector<int> res = {nums[q.front()]};

        // 更新后续窗口
        for (int i = k; i < n; i++) {
            // 清除队尾比当前数字小的元素
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();

            // 清除队头不在窗口中的数据
            while (!q.empty() && q.front() <= i - k) q.pop_front();

            // 推入当前元素到队尾
            q.push_back(i);

            // 保存当前窗口的最大值
            res.push_back(nums[q.front()]);
        }

        return res;
    }
};