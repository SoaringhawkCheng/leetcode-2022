//
// Created by 成翔昊 on 2022/10/19.
//

// 有一个列表、存的是存取记录Record
// 银行每天都会发放奖励，存在dailyAwards里
// 奖励当前按用户存款&时间占比分配，存取记录即可生效无延迟
// 求：
//      当dailyAwards按时间无序时，每个用户最终得了多少奖

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

struct BankRecord {
    string userId; //
    bool type; // true: 存   false：取
    long timestamp; // 时间戳
    long cash; // 分
};

class BankRewardRaw {
private:
    vector<int> dailyAwards;
    vector<BankRecord> records;
    long beginTime;
    const static long ONE_DAY = 24 * 3600;

    unordered_map<string, long> userAwardMap;

public:
    BankRewardRaw(vector<int> dailyAwards, vector<BankRecord> records, long beginTime) {
        this->dailyAwards = dailyAwards;
        this->records = records;
        this->beginTime = beginTime;
    }

    unordered_map<string, long> countuserAwardMap() {
        unordered_map<string, map<long, long>> userSaveHistory;

        // 保存用户维度的存取记录
        for (auto record: records) {
            long cash = record.type ? record.cash : -record.cash;
            // 活动开始之前的记录，进行叠加统一计算
            if (record.timestamp <= beginTime) {
                userSaveHistory[record.userId][beginTime] += cash;
            } else {
                userSaveHistory[record.userId][record.timestamp] = cash;
            }
        }

        vector<map<string, long>> dailyUserCntList = vector<map<string, long>>(dailyAwards.size(), map<string, long>());

        // 计算用户在天维度下的加权
        for (auto userIter: userSaveHistory) {
            string userId = userIter.first;
            for (auto saveIter: userIter.second) {
                int day = (saveIter.first - beginTime) / ONE_DAY;
                long dayBeginTime = beginTime + day * ONE_DAY;

                // 存取记录当天
                dailyUserCntList[day][userId] = (saveIter.first - dayBeginTime) * saveIter.second;

                // 后续天
                for (int i = day + 1; i < dailyAwards.size(); i++)
                    dailyUserCntList[day][userId] = saveIter.second * ONE_DAY;
            }
        }

        // 计算每天的发钱
        for (int i = 0; i < dailyAwards.size(); i++) {
            long cnt = 0;
            for (auto userCnt: dailyUserCntList[i]) {
                cnt += userCnt.second;
            }
            for (auto userCnt: dailyUserCntList[i]) {
                userAwardMap[userCnt.first] += (userCnt.second * dailyAwards[i]) / cnt;
            }
        }

        return userAwardMap;
    }
};