//
// Created by 成翔昊 on 2022/10/13.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        if (height.empty()) return 0;
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());
        for (int i = 1; i < height.size(); i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
        }

        for (int i = height.size() - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], height[i + 1]);
        }

        int volume = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            int minBorder = min(maxLeft[i], maxRight[i]);
            if (minBorder > height[i])
                volume += (minBorder - height[i]);
        }

        return volume;
    }
};