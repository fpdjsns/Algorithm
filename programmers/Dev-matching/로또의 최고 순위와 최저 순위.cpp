/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/77484
 * time complexity : O(N + M) // N = |lottos|, M = |win_nums|
 */

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> score = {6, 6, 5, 4, 3, 2, 1}; // 순위
    
    int matchCnt = 0;
    int wrongCnt = 0;
    set<int> winSet;
    for(auto num: win_nums) {
        winSet.insert(num);
    }
    for(auto num: lottos) {
        if(num == 0) wrongCnt++;
        else if(winSet.find(num) != winSet.end()) matchCnt++;
    }
    
    return {score[matchCnt + wrongCnt], score[matchCnt]};
}
