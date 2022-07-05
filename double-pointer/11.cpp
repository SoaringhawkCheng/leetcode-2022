//
// Created by 成翔昊 on 2022/6/30.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // s(left,right) = min(h[left], h[right]) * (right-left)
    // 如果向内移动长板，min(h[left], h[right])不会变大，s一定变小
    // 比如h[left]<h[right]，s(h[left], h[*])一定面积更小
    // 所以可以向内移动短板，消除这些s
    int maxArea(vector<int> &height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            res = max(res, area);
            if (height[l] <= height[r]) ++l;
            else --r;
        }
        return res;
    }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << s.maxArea(height) << endl;
}