//
// Created by 成翔昊 on 2022/7/8.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int left, right, size;
    string path;
    vector<string> result;
public:
    vector<string> generateParenthesis(int n) {
        size = n;
        dfs();
        return result;
    }

private:
    void dfs() {
        if (path.size() == 2 * size) {
            result.push_back(path);
            return;
        }

        if (left < size) {
            path.push_back('(');
            left++;
            dfs();
            left--;
            path.pop_back();
        }

        if (left>right) {
            path.push_back(')');
            right++;
            dfs();
            right--;
            path.pop_back();
        }

    }
};