//
// Created by 成翔昊 on 2022/4/5.
//

#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> in;
    stack<int> out;
public:
    MyQueue() {

    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        if (out.empty()) in2out();
        int res = out.top();
        out.pop();
        return res;
    }

    int peek() {
        if (out.empty()) in2out();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }

private:
    void in2out() {
        while (!in.empty()) {
            int top = in.top();
            out.push(top);
            in.pop();
        }
    }
};