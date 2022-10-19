//
// Created by 成翔昊 on 2022/10/16.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.empty()) return 0;

        int size = ratings.size();
        vector<int> candies = vector<int>(size, 1);
        for (int i = 1; i < size; i++) {
            if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
        }

        for (int i = size - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) candies[i] = max(candies[i], candies[i + 1] + 1);
        }

        int cnt = 0;
        for (int i = 0; i < size; i++) cnt += candies[i];

        return cnt;
    }
};