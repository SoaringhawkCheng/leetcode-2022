//
// Created by 成翔昊 on 2022/4/14.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
public:
    int minPath(vector<vector<string>> nets, string source, string target) {
        queue<int> q;

        unordered_map<string, vector<int>> hostMap = parseNet(nets);
        if (hostMap.find(source) == hostMap.end() || hostMap.find(target) == hostMap.end()) {
            return -1;
        }

        unordered_set<int> visited;
        vector<int> sourceNetList = hostMap[source];
        for (int i = 0; i < sourceNetList.size(); i++) {
            q.push(sourceNetList[i]);
            visited.insert(i);
        }

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int currNet = q.front();
                q.pop();
                vector<string> currNetHosts = nets[currNet];
                if (find(currNetHosts.begin(), currNetHosts.end(), target) != currNetHosts.end()) {
                    return level;
                }

                vector<int> nearbyNets = findNearbyNets(currNet, nets, hostMap, visited);
                for (int j = 0; j < nearbyNets.size(); j++) {
                    q.push(nearbyNets[j]);
                }

            }
            level += 1;
        }

        return -1;
    }

private:
    unordered_map<string, vector<int>> parseNet(vector<vector<string>> nets) {
        unordered_map<string, vector<int>> hostMap;

        for (int i = 0; i < nets.size(); i++) {
            for (int j = 0; j < nets[i].size(); j++) {
                string host = nets[i][j];
                if (hostMap.find(host) == hostMap.end()) {
                    hostMap[host] = vector<int>();
                }
                vector<int> &hostList = hostMap[host];
                hostList.push_back(i);
            }
        }

        return hostMap;
    }

    vector<int> findNearbyNets(int net, vector<vector<string>> &nets, unordered_map<string, vector<int>> &hostMap,
                               unordered_set<int> &visited) {
        vector<int> nearbyNets;
        vector<string> hostList = nets[net];
        for (int i = 0; i < hostList.size(); i++) {
            vector<int> netList = hostMap[hostList[i]];
            for (int j = 0; j < netList.size(); j++) {
                if (visited.find(netList[j]) == visited.end()) {
                    nearbyNets.push_back(netList[j]);
                    visited.insert(netList[j]);
                }
            }
        }

        return nearbyNets;
    }

};

int main() {
    vector<vector<string>> nets = {{"host1", "host2", "host3"},
//                                   {"host1", "host4"},
                                   {"host2", "host5"},
                                   {"host3", "host4"},
                                   {"host4", "host5", "host6"},
                                   {"host6", "host7"}};

    Solution s;
    cout << s.minPath(nets, "host1", "host7") << endl;
}