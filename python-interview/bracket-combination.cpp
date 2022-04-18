//
// Created by 成翔昊 on 2022/4/18.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    int countDown;
    string brackets;
    int limit;
    string currStr;
    vector<string> result;
public:
    Solution() : countDown(0), brackets("()") {}

    vector<string> generateParenthesis(int n) { // DFS
        limit = n;
        dfs();
        return result;
    }

    void dfs() {
        if (currStr.size() == 2 * limit) {
            if (countDown == 0) {
                result.push_back(currStr);
            }
            return;
        }

        if (countDown < limit) {
            currStr.push_back(brackets[0]);
            countDown++;
            dfs();
            countDown--;
            currStr.pop_back();
        }

        if (countDown > 0) {
            currStr.push_back(brackets[1]);
            countDown--;
            dfs();
            countDown++;
            currStr.pop_back();
        }
    }
};