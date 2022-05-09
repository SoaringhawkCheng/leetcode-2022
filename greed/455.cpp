//
// Created by 成翔昊 on 2022/5/4.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        for (int i = 0, j = 0; i < g.size() && j < s.size(); i++, j++) {
            while (j < s.size() && g[i] > s[j]) j++;
            if (j < s.size()) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution solution;
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << solution.findContentChildren(g, s) << endl;
}