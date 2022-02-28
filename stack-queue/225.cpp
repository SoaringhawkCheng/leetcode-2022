//
// Created by 成翔昊 on 2022/2/20.
//

#include "stack_queue.h"

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        q.push_back(x);
    }

    int pop() {
        int result = q.back();
        q.pop_back();
        return result;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }

    deque<int> q;
};

//int main() {
//    MyStack s;
//    s.push(1);
//    s.push(2);
//    cout << s.top() <<endl;
//    cout <<s.pop()<<endl;
//    cout <<s.empty()<<endl;
//    for (auto num: s.q) {
//        cout << num << " ";
//    }
//    cout << endl;
//}