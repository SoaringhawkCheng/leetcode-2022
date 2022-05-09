//
// Created by 成翔昊 on 2022/5/9.
//

#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int prev = -1, count = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 1) {
                if (prev < 0) {
                    count += i / 2;
                } else {
                    int diff = i - prev;
                    count += diff >= 2 ? diff / 2 - 1 : 0;
                }
                prev = i;
            }
        }

        // 一个1都没有
        if (prev < 0) {
            count += (flowerbed.size() + 1) / 2;
        } else {
            count += (flowerbed.size() - prev - 1) / 2;
        }

        return count >= n;
    }
};