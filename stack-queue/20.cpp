//
// Created by 成翔昊 on 2022/7/8.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto &ch: s) {
            if (ch == ')') {
                if (stk.empty() || stk.top() != '(') return false;
                stk.pop();
            }
            else if (ch == '}') {
                if (stk.empty() || stk.top() != '{') return false;
                stk.pop();
            }
            else if (ch == ']') {
                if (stk.empty() || stk.top() != '[') return false;
                stk.pop();
            } else stk.push(ch);
        }
        return stk.empty();
    }
};