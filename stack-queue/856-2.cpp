//
// Created by 成翔昊 on 2022/7/8.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
private:
    stack<char> stk;
public:
    int scoreOfParentheses(string s) {
        int deep = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') deep++;
            else {
                deep--;
                if (i > 0 && s[i - 1] == '(') res += (1 << deep);
            }
        }
        return res;
    }
};