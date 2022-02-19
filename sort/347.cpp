//
// Created by 成翔昊 on 2022/2/19.
//

#include "sort.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freqMap;
        for (auto num: nums) {
            auto iter = freqMap.find(num);
            if (iter == freqMap.end()) {
                freqMap[num] = 1;
            } else {
                freqMap[num]++;
            }
        }

        vector<vector<int>> freqBucket(nums.size() + 1, vector<int>());
        for (auto iter: freqMap) {
//            cout << iter.first << " " << iter.second << endl;
            vector<int> &buckList = freqBucket[iter.second];
            buckList.push_back(iter.first);
        }

        vector<int> result;
        if (k <= 0) {
            return result;
        }

        for (int i = nums.size(); i > 0; i--) {
            auto buckList = freqBucket[i];
            for (auto num: buckList) {
//                cout << num << " ";
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
//            cout << endl;
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    Solution s;
    for (auto num: s.topKFrequent(nums, 2))
        cout << num << " ";
    cout << endl;
}