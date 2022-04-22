//
// Created by 成翔昊 on 2022/4/5.
//

#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> stk;
        for (int i = 0, j = 0; i < pushed.size(); i++) {
            stk.push(pushed[i]);
            while (!stk.empty() && j < popped.size() && popped[j] == stk.top()) {
                stk.pop();
                j++;
            }
        }

        return stk.empty();
    }
};

int main() {
    Solution s;
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {5, 3, 4, 2, 1};
    cout << s.validateStackSequences(pushed, popped) << endl;
}