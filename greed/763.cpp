//
// Created by 成翔昊 on 2022/5/9.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndexMap;
        vector<int> partition;
        for (int i = 0; i < s.size(); i++) {
            lastIndexMap[s[i]] = i;
        }
        int start = 0, end = -1;
        for (int i = 0; i < s.size(); i++) {
            int lastIndex = lastIndexMap[s[i]];
            end = max(end, lastIndex);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};