//
// Created by 成翔昊 on 2022/7/8.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int left, right;
    string str, path;
    unordered_map<string, bool> exists;
    vector<string> result;
public:
    // 1. 先计算出需要删除的左括号和右括号的数量
    // 2. 使用回溯列出删除的组合，并对组合进行校验
    vector<string> removeInvalidParentheses(string s) {
        str = s;
        countToDelete();
        backtracking(0);
        return result;
    }

private:
    void countToDelete() {
        for (auto &ch: str) {
            if (ch == '(') left++;
            if (ch == ')') {
                if (left > 0) left--;
                else right++;
            }
        }
    }

    void backtracking(int index) {
        if (str.size() - index < left + right) return;

        if (index == str.size()) {
            if (validate() && exists.find(path) == exists.end()) {
                exists[path] = true;
                result.push_back(path);
            }
            return;
        }

        if (str[index] == '(' && left > 0) {
            left--;
            backtracking(index + 1);
            left++;
        }

        if (str[index] == ')' && right > 0) {
            right--;
            backtracking(index + 1);
            right++;
        }

        path.push_back(str[index]);
        backtracking(index + 1);
        path.pop_back();
    }

    bool validate() {
        int cnt = 0;
        for (auto &ch: path) {
            if (ch == '(') cnt++;
            if (ch == ')') {
                if (cnt > 0) cnt--;
                else return false;
            }
        }

        return cnt == 0;
    }
};

int main() {
    string str = "(a)())()";
    Solution s;
    vector<string> result = s.removeInvalidParentheses(str);
    for (auto res: result) cout << res << " ";
}