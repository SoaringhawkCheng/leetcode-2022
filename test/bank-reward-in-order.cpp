//
// Created by 成翔昊 on 2022/10/19.
//

// 有一个列表、存的是存取记录Record
// 银行每天都会发放奖励，存在dailyAwards里
// 奖励当前按用户存款&时间占比分配，存取记录即可生效无延迟
// 求：
//      当dailyAwards按时间有序是，最快的计算方式

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

class BankRewardInOrder {
private:
    vector<int> dailyAwards;
    vector<BankRecord> records;
    long beginTime;
    const static long ONE_DAY = 24 * 3600;

    unordered_map<string, long> userAwardMap;

public:
    BankRewardInOrder(vector<int> dailyAwards, vector<BankRecord> records, long beginTime) {
        this->dailyAwards = dailyAwards;
        this->records = records;
        this->beginTime = beginTime;
    }

    unordered_map<string, long> countUserAward() {
        vector<map<string, long>> dailyUserCntList = vector<map<string, long>>(dailyAwards.size(), map<string, long>());
        unordered_map<string, long> userCurrSaveMap;

        // 活动开始前的记录合并计算
        int index = 0;
        while (index < records.size()) {
            BankRecord record = records[index];
            if (record.timestamp > beginTime) break;

            userCurrSaveMap[record.userId] += (record.type ? record.cash : -record.cash);
            if (userCurrSaveMap[record.userId] == 0) userCurrSaveMap.erase(record.userId);
            index++;
        }

        // 计算每天的奖金分配
        for (int i = 1; i <= dailyAwards.size(); i++) {
            long dayEndTime = beginTime + i * ONE_DAY;

            // 捞出当前天的记录
            unordered_map<string, vector<BankRecord>> userDayRecordMap;
            while (index < records.size()) {
                BankRecord record = records[index];
                if (record.timestamp > dayEndTime) break;

                userDayRecordMap[record.userId].push_back(record);
                index++;
            }

            // 计算当前天的用户加权
            unordered_map<string, long> userCountMap;
            for (auto userSave: userCurrSaveMap) {
                string userId = userSave.first;
                userCountMap[userId] = userSave.second * ONE_DAY;

                for (auto userRecord: userDayRecordMap[userId]) {
                    long cash = (userRecord.type ? userRecord.cash : -userRecord.cash);
                    userCountMap[userId] += (cash * (dayEndTime - userRecord.timestamp));
                    // 更新当前存储金额
                    userSave.second += cash;
                }
            }

            // 用户当前天奖金到账
            long totalCount = 0;
            for (auto userCount: userCountMap) totalCount += userCount.second;
            for (auto userCount: userCountMap)
                userAwardMap[userCount.first] += (userCount.second * dailyAwards[i]) / totalCount;
        }

        return userAwardMap;
    }
};