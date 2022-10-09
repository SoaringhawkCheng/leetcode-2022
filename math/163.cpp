//
// Created by 成翔昊 on 2022/10/9.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        vector<string> results;
        vector<int> realNums;
        realNums.push_back(lower - 1);
        for (auto num: nums) realNums.push_back(num);
        realNums.push_back(upper + 1);
        for (int i = 0; i < realNums.size() - 1; i++) {
            if (realNums[i + 1] - realNums[i] == 2) {
                results.push_back(to_string(realNums[i] + 1));
            }

            if (realNums[i + 1] - realNums[i] > 2) {
                results.push_back(to_string(realNums[i] + 1) + "->" + to_string(realNums[i + 1] - 1));
            }
        }

        return results;
    }
};