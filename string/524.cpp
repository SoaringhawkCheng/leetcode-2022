//
// Created by 成翔昊 on 2022/5/2.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string> &dictionary) {
        string res;
        for (string substr: dictionary) {
            if (substr.size() < res.size() || (substr.size() == res.size() && substr.compare(res) > 0)) continue;
            if (isSubstring(s,substr)) res = substr;
        }

        return res;
    }

private:
    bool isSubstring(string s, string substr) {
        int i = 0, j = 0;
        while (i < s.size() && j < substr.size()) {
            if (s[i] == substr[j]) {
                ++j;
            }
            ++i;
        }
        return j==substr.size();
    }
};