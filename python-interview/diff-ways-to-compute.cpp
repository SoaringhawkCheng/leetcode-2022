//
// Created by 成翔昊 on 2022/4/19.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    typedef string::iterator Iter;
public:
    vector<int> diffWaysToCompute(string expression) {
        return diffWaysToCompute(expression, expression.begin(), expression.end());
    }

private:
    vector<int> diffWaysToCompute(const string &exp, Iter begin, Iter end) {
        vector<int> result;

        int num = convertToNumber(begin, end);
        if (num >= 0) {
            result.push_back(num);
            return result;
        }

        for (auto iter = begin; iter != end; iter++) {
            if (isOperation(*iter)) {
                vector<int> lhsRes = diffWaysToCompute(exp, begin, iter);
                vector<int> rhsRes = diffWaysToCompute(exp, next(iter), end);
                for (int j = 0; j < lhsRes.size(); j++) {
                    for (int k = 0; k < rhsRes.size(); k++) {
                        result.push_back(calculate(lhsRes[j], rhsRes[k], *iter));
                    }
                }
            }
        }

        return result;
    }

    int calculate(int lhs, int rhs, char c) {
        switch (c) {
            case '+':
                return lhs + rhs;
            case '-':
                return lhs - rhs;
            case '*':
                return lhs * rhs;
        }
        return -1;
    }

    bool isOperation(char c) {
        return c == '+' || c == '-' || c == '*';
    }

    int convertToNumber(Iter begin, Iter end) {
        int num = 0;
        for (auto iter = begin; iter != end; iter++) {
            if (*iter < '0' || *iter > '9') {
                return -1;
            }
            num = num * 10 + (*iter - '0');
        }
        return num;
    }
};

int main() {
    Solution s;
    vector<int> results = s.diffWaysToCompute("2-1-1");
    for (auto result:results) {
        cout << result<< " ";
    }
}