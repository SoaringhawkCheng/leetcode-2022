//
// Created by 成翔昊 on 2022/9/27.
//

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        if(tasks.empty()) return 0;

        unordered_map<char, int> taskCnt;
        for (char task: tasks) {
            taskCnt[task]++;
        }

        unordered_map<int, int> cntTasks;
        for (auto iter = taskCnt.begin(); iter != taskCnt.end(); iter++) {
            cntTasks[iter->second]++;
        }

        int maxTaskTime = 0, maxTimeCnt = 0;
        for (auto iter = cntTasks.begin(); iter != cntTasks.end(); iter++) {
            if (iter->first > maxTaskTime) {
                maxTaskTime = iter->first; maxTimeCnt = iter->second;
            }
        }

        return max((maxTaskTime-1)*(n+1)+maxTimeCnt, (int) tasks.size());
    }
};