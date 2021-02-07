/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/72411?language=cpp
 */
 
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void setCombiCnt(string& order, int ind, string combi, 
                 unordered_map<string, int>& cntMap,
                 set<int> courseSet) {
    string tmp;
    for(int i = ind; i < order.size(); i++){
        tmp = combi + order[i];
        if(courseSet.find(tmp.size()) != courseSet.end())
            cntMap[tmp]++;
        setCombiCnt(order, i+1, tmp, cntMap, courseSet);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    unordered_map<string, int> cntMap;
    set<int> courseSet;
    for(auto cnt: course) courseSet.insert(cnt);
    
    for(string order: orders) {
        sort(order.begin(), order.end());
        setCombiCnt(order, 0, "", cntMap, courseSet);
    }
    
    // key : length, value : string answer
    unordered_map<int, vector<pair<int, string>>> combiMap;
    for(auto now: cntMap) {
        string combi = now.first;
        int cnt = now.second;
        if(cnt < 2) continue;
        combiMap[combi.size()].push_back({-cnt, combi});
    }
    
    vector<string> answer;
    for(auto now: combiMap) {
        vector<pair<int, string>> combis = now.second;
        // desc by cnt
        sort(combis.begin(), combis.end());
        for(int i = 0; i < combis.size(); i++) {
            if(i > 0 && combis[i].first != combis[i-1].first) break;
            answer.push_back(combis[i].second);
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}
