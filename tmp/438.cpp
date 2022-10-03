//
// Created by 成翔昊 on 2022/7/29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> res;

        // ========================构建窗口========================
        vector<int> count(26);
        for (int i = 0; i < pLen; i++) {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }

        int differ = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) ++differ; // 统计数量不匹配的字符个数
        }

        if (differ == 0) res.push_back(0);

        // ========================滑动窗口========================
        for (int i = 0; i < sLen - pLen; ++i) {
            // 推出
            if (count[s[i] - 'a'] == 1) --differ;
            else if (count[s[i] - 'a'] == 0) ++differ;
            --count[s[i] - 'a'];
            // 推入
            if (count[s[i + pLen] - 'a'] == -1) --differ;
            else if (count[s[i + pLen] - 'a'] == 0) ++differ;
            ++count[s[i + pLen] - 'a'];

            if (differ == 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};

