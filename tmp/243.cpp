//
// Created by 成翔昊 on 2022/10/3.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string> &wordsDict, string word1, string word2) {
        int recentIndex1 = -1, recentIndex2 = -1;
        int minDis = INT_MAX;
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) {
                if (recentIndex2 >= 0)
                    minDis = min(minDis, i - recentIndex2);
                recentIndex1 = i;
            }

            if (wordsDict[i] == word2) {
                if (recentIndex1 >= 0)
                    minDis = min(minDis, i - recentIndex1);
                recentIndex2 = i;
            }
        }

        return minDis;
    }
};