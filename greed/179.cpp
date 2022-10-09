//
// Created by 成翔昊 on 2022/10/9.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        string result;
        sort(nums.begin(), nums.end(), compare);
        for (auto num: nums)
            result += to_string(num);

        auto iter = result.begin();
        while (*iter == '0') iter++;
        return iter == result.end() ? "0" : result.substr(iter - result.begin(), result.end() - iter);
    }

private:
    static bool compare(int lhs, int rhs) {
        return to_string(lhs) + to_string(rhs) > to_string(rhs) + to_string(lhs);
    }
};

int main() {
    cout << ("30" > "3") << endl;
    cout << ("30" < "3") << endl;
    cout << ("30" == "3") << endl;
}