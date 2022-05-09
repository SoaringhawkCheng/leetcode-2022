//
// Created by 成翔昊 on 2022/5/9.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // 队列中的人由[h,k]表示，h表示身高，k表示前面身高大于等于他的数量
    // 先按身高从高到低，排名从低到高排名，然后从做到右遍历插入
    // 后插入的元素，有两种情况
    //
    // 身高更矮的，插入到现有入队人的前面，不影响现有的队列
    // 身高相同的，排名更靠后的，由于前面插入的都是身高不矮于他的，所以直接放在k+1的位置
    // 一个人的k肯定比排序的位置小，所以直接插入就行
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> queue;
        for (int i = 0; i < people.size(); i++) {
            queue.insert(queue.begin() + people[i][1], people[i]);
        }
        return queue;
    }

private:
    static bool compare(const vector<int> &lhs, const vector<int> &rhs) {
        return lhs[0] > rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
    }
};

int main() {
    vector<vector<int>> people = {{7, 0},
                                  {4, 4},
                                  {7, 1},
                                  {5, 0},
                                  {6, 1},
                                  {5, 2}};
    Solution s;
    vector<vector<int>> queue = s.reconstructQueue(people);
    for (auto person: queue) {
        cout << person[0] << " " << person[1] << endl;
    }
}