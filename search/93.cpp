//
// Created by 成翔昊 on 2022/5/10.
//

#include <vector>
#include <string>
#include <iterator>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<vector<string>> ipSegList;
        vector<string> currIpSeg;
        dfs(s, 0, 0, currIpSeg, ipSegList);
        vector<string> res;
        for (auto ipSeg: ipSegList) {
            res.push_back(ipSeg[0] + "." + ipSeg[1] + "." + ipSeg[2] + "." + ipSeg[3]);
        }
        return res;
    }

private:
    void dfs(const string &s, int step, int index, vector<string> &currIpSeg, vector<vector<string>> &ipSegList) {
        if (step == 3) {
            string subStr = s.substr(index, s.size() - index);
            if (isIpSeg(subStr)) {
                currIpSeg.push_back(subStr);
                ipSegList.push_back(currIpSeg);
                currIpSeg.pop_back();
            }
            return;
        }

        for (int end = index + 1; end <= s.size(); end++) {
            string subStr = s.substr(index, end - index);
            if (!isIpSeg(subStr)) continue;

            currIpSeg.push_back(subStr);
            dfs(s, step + 1, end, currIpSeg, ipSegList);
            currIpSeg.pop_back();
        }
    }

public:
    bool isIpSeg(string subStr) {
        if (subStr.empty() || subStr.size() > 3 || (subStr.size() > 1 && subStr[0] == '0')) return false;
        int seg = 0;
        for (int i = 0; i < subStr.size(); i++) {
            seg = seg * 10 + (subStr[i] - '0');
        }

        return seg <= 255;
    }
};

int main() {
    Solution s;
    vector<string> ipList = s.restoreIpAddresses("25525511135");
    for (auto ip: ipList) cout << ip << endl;
//    cout << s.isIpSeg("255") << endl;
}