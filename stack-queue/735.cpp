//
// Created by 成翔昊 on 2022/7/21.
//

#include <iostream>
#include <vector>
//#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vector<int> res;
        for (auto &num: asteroids) {
            // 如果num是正数，直接推入
            if (num > 0) {
                res.push_back(num);
                continue;
            }

            // num是负数

            // 队尾有比当前num绝对值小的正数，循环推出
            while (!res.empty() && res.back() > 0 && res.back() + num < 0) res.pop_back();

            // 队列为空，或者队尾是负数，推入
            if (res.empty() || res.back() < 0) res.push_back(num);
            // 队尾是正数，且两者相撞会消失
            else if (res.back() + num == 0) res.pop_back();
        }

        return res;
    }
};