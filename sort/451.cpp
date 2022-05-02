//
// Created by 成翔昊 on 2022/5/2.
//

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        int maxFreq = 0;
        for (auto ch: s) {
            maxFreq = max(maxFreq, ++freqMap[ch]);
        }

        vector<string> buckets(maxFreq + 1, "");

        for (auto chFreq: freqMap) {
            buckets[chFreq.second].push_back(chFreq.first);
        }

        string res;
        for (int i = buckets.size() - 1; i > 0; i--) {
            for (auto ch: buckets[i]) {
                for (int j = 0; j < i; j++)
                    res.push_back(ch);
            }
        }

        return res;
    }
};