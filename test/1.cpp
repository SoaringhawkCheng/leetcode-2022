//
// Created by 成翔昊 on 2022/3/22.
//

#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    string multiple(string lhs, string rhs) {
        if (lhs.empty() || rhs.empty()) return "0";

//        int totalResult = 0;
        int totalBase = 0;

        vector<int> totalResult(lhs.size() + rhs.size(), 0);

        for (int j = rhs.size() - 1; j >= 0; j--) {
            int multiNum = rhs[j] - '0';
            int base = totalBase;
            int carrybit = 0;
            vector<int> result;
            for (int i = lhs.size() - 1; i >= 0; i--) {
                result.push_back(0);
                int num = lhs[i] - '0';
                int singleMultiResult = num * multiNum + carrybit;
                result[lhs.size() - 1 - i] += singleMultiResult % 10;
                carrybit = singleMultiResult / 10;
            }
            if (carrybit > 0) result.push_back(carrybit);
            totalBase *= 10;
        }

    }

    void add(vector)

////        reverse(totalResultStr.begin(), totalResultStr.end());
////        return totalResultStr;
//    }

private:

};

int main() {
    Solution s;
    cout << s.multiple("12345678", "456789") << endl;
}