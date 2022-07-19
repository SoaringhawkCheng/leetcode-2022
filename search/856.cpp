//
// Created by 成翔昊 on 2022/7/8.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        return scoreOfParentheses(s, 0, s.size());
    }

private:
    int scoreOfParentheses(const string &s, int begin, int end) {
        int balance = 0, res = 0;
        for (int i = begin; i < end; i++) {
            balance += s[i] == '(' ? 1 : -1;
            if (balance == 0) {
                if (i - begin == 1) res++;
                else res += 2 * scoreOfParentheses(s, begin + 1, i);
                begin = i + 1;
            }
        }
        return res;
    }
};

int main() {
    string str = "()()";
    Solution s;
    cout << s.scoreOfParentheses(str) << endl;
}