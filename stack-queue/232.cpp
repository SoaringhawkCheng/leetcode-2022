//
// Created by 成翔昊 on 2022/2/20.
//

#include "stack_queue.h"

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        in2out();
        int result = out.top();
        out.pop();
        return result;
    }

    int peek() {
        in2out();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }

    void in2out() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }

private:
    stack<int> in;
    stack<int> out;
};