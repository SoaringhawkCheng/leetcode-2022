//
// Created by 成翔昊 on 2022/4/11.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        } else {
            return longestCommonPrefix(strs, 0, strs.size() - 1);
        }
    }

    string longestCommonPrefix(const vector<string> &strs, int start, int end) {
        if (start == end) {
            return strs[start];
        } else {
            int mid = start + (end - start) / 2;
            string leftStr = longestCommonPrefix(strs, start, mid);
            string rightStr = longestCommonPrefix(strs, mid + 1, end);
            return commonPrefix(leftStr, rightStr);
        }
    }

    string commonPrefix(const string &leftStr, const string &rightStr) {
        int minLength = min(leftStr.size(), rightStr.size());
        int index = 0;
        string commonStr = "";
        while (index < minLength && leftStr[index] == rightStr[index]) {
            commonStr.push_back(leftStr[index++]);
        }

        return commonStr;
    }
};

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
}