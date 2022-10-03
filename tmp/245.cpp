//
// Created by 成翔昊 on 2022/10/3.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string> &wordsDict, string word1, string word2) {

        if (word1 == word2) {
            int index = -1, minDis = INT_MAX;
            for (int i = 0; i < wordsDict.size(); i++) {
                if (wordsDict[i] != word1) continue;
                if (index >= 0)
                    minDis = min(minDis, i - index);
                index = i;
            }
            return minDis;
        } else {
            int index1 = -1, index2 = -1, minDis = INT_MAX;
            for (int i = 0; i < wordsDict.size(); i++) {
                if (wordsDict[i] == word1) {
                    if (index2 >= 0) minDis = min(minDis, i - index2);
                    index1 = i;
                }
                if (wordsDict[i] == word2) {
                    if (index1 >= 0) minDis = min(minDis, i - index1);
                    index2 = i;
                }
            }
            return minDis;
        }
    }
};