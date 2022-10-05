//
// Created by 成翔昊 on 2022/10/4.
//

#include <iostream>
//#include
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            int bitC = (c >> i) & 1;
            if (bitC == 0)
                ans += bitA + bitB;
            else ans += (bitA == 0 && bitB == 0);
        }

        return ans;
    }
};