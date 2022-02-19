//
// Created by 成翔昊 on 2022/2/9.
//

class Solution {
public:
    int climbStairs(int n) {
        if (n==0||n==1) {
            return 1;
        }

        int prev = 1;
        int current = 1;
        for (int index = 2; index < n+1; index++) {
            int tmp = current;
            current = current + prev;
            prev = tmp;
        }

        return current;
    }
};
