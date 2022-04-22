//
// Created by 成翔昊 on 2022/4/5.
//

#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> stk;
    stack<int> min_stk;
public:
    MinStack() {
        min_stk.push(INT_MAX);
    }

    void push(int val) {
        stk.push(val);
        min_stk.push(min(min_stk.top(), val));
    }

    void pop() {
        stk.pop();
        min_stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
    }
};