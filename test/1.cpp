//
// Created by 成翔昊 on 2022/3/22.
//

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int calcMaxDiff(vector<int> nums) {
        if (nums.size() < 2) return 0;
        int leftMin = nums[0], maxDiff = 0;
        for (int i = 1; i < nums.size(); i++) {
            maxDiff = max(maxDiff, nums[i] - leftMin);
            leftMin = min(leftMin, nums[i]);
        }
        return maxDiff;
    }
};


int main() {
    return 0;
}