//
// Created by 成翔昊 on 2022/11/19.
//

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<char, int> charCntMap; //
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() < 3) return s.size();

        int maxLen = 0;
        int left = 0;
        int count = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            if (charCntMap[c] == 0) {
                count++;
            }

            charCntMap[c]++;

            while (count > 2) {
                charCntMap[s[left]]--;
                if (charCntMap[s[left]] == 0) count--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};