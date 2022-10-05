//
// Created by 成翔昊 on 2022/10/3.
//

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
private:
    int level;
    stack<int> used;
    vector<int> nums1, nums2;
    int currLines;
    int maxLines;
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.empty() || nums2.empty()) return 0;

        this->nums1 = nums1, this->nums2 = nums2;
        level = 0, currLines = 0, maxLines = 0;
        dfs();
        return maxLines;
    }

private:
    void dfs() {
        if (level == nums1.size()) {
            maxLines = max(maxLines, currLines);
            return;
        }

        int lastUsedIdx = used.empty() ? -1 : used.top();

        for (int i = lastUsedIdx + 1; i < nums2.size(); i++) {
            if (nums1[level] != nums2[i]) continue;
            used.push(i);
            level++, currLines++;
            dfs();
            level--, currLines--;
            used.pop();
        }

        level++;
        dfs();
        level--;
    }
};

int main() {
    vector<int> nums1 = {1, 4, 2};
    vector<int> nums2 = {1, 2, 4};
    Solution s;
    cout << s.maxUncrossedLines(nums1, nums2) << endl;
}