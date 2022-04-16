//
// Created by 成翔昊 on 2022/4/16.
//

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() > nums1.size()) {
            return intersect(nums2, nums1);
        }

        unordered_map<int, int> numMap;
        for (auto num: nums1) {
            if (numMap.find(num) == numMap.end()) {
                numMap[num] = 0;
            }
            numMap[num]++;
        }

        vector<int> result;
        for (auto num: nums2) {
            if (numMap.find(num) != numMap.end() && numMap[num] > 0) {
                numMap[num]--;
                result.push_back(num);
            }
        }

        return result;
    }
};