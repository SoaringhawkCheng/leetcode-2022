//
// Created by 成翔昊 on 2022/5/10.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> keys;
public:
    vector<string> letterCombinations(string digits) {
        keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path;
        vector<string> res;
        dfs(digits, res, path, 0);
        return res;
    }

private:
    void dfs(const string &digits, vector<string> &res, string &path, int step) {
        if (step >= digits.size()) {
            if (!path.empty()) res.push_back(path);
            return;
        }

        int index = digits[step] - '0';
        for (auto ch:keys[index]) {
            path.push_back(ch);
            dfs(digits, res, path, step+1);
            path.pop_back();
        }
    }
};