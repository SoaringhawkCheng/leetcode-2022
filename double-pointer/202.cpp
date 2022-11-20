//
// Created by 成翔昊 on 2022/11/4.
//

// (1^2+9^2) = 82
// (8^2+2^2) = 64+4 = 70
// (7^2+0^2) = 49
// (4^2+9^2) = 16+81 = 97
// (9^2+7^2) = 81+49 = 130
// (1^2+3^2+0^2) = 10
// (1^2+0^0) = 1

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (fast != 1) {
            fast = calcSquareSum(calcSquareSum(fast));
            slow = calcSquareSum(slow);
            if (fast != 1 && fast == slow) return false;
        }
        return true;
    }

private:
    int calcSquareSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10) * (num % 10);
            num /= 10;
        }
    }
};