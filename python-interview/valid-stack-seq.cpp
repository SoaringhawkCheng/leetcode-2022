//
// Created by 成翔昊 on 2022/4/13.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> stk;

        if (pushed.size() != popped.size()) {
            return false;
        }

        for (int i = 0, j = 0; i < pushed.size(); i++) {
            stk.push(pushed[i]);
            while (!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
        }

        return stk.empty();
    }
};

int main() {

}