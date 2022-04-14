//
// Created by 成翔昊 on 2022/4/12.
//

#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int maxLen = 0, left = 0;
        unordered_set<char> lookup;

        for (int i = 0; i < size; i++) {
            while (lookup.find(s[i]) != lookup.end()) {
                lookup.erase(s[left]);
                left++;
            }

            maxLen = max(maxLen, i - left + 1);
            lookup.insert(s[i]);
        }

        return maxLen;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcdcdasliehsodcsas") << endl;
}