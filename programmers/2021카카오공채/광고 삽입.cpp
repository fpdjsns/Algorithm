/**
 * prooblem : https://programmers.co.kr/learn/courses/30/lessons/72414
 * time complexity : O(N) // N = seconds of play_time
 * algorithm : subsum
 */
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int getSecond(string time) {
    int second =  60 * 60 * (10 * (time[0] - '0') + time[1] - '0');
    second += 60 * (10 * (time[3] - '0') + time[4] - '0');
    second += 10 * (time[6] - '0') + time[7] - '0';
    return second;
}

string getString(int second) {
    
    vector<int> times(3);
    times[0] = second / (60 * 60);
    second %= (60 * 60);
    times[1] = second / 60;
    second %= 60;
    times[2] = second;
    
    
    string answer = "";
    for(int time : times){
        answer.push_back((time / 10) + '0');
        answer.push_back((time % 10) + '0');
        if(answer.size() < 8) answer.push_back(':');
    }
    return answer;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int playTime = getSecond(play_time);
    int advTime = getSecond(adv_time);
    
    vector<long long int> subSum(playTime+1, 0);
    for(string log: logs){
        subSum[getSecond(log.substr(0, 8))]++;
        subSum[getSecond(log.substr(9, 8))]--;
    }
    for(int i=1; i<=playTime; i++)
        subSum[i] += subSum[i-1];
    for(int i=1; i<=playTime; i++)
        subSum[i] += subSum[i-1];

    int answer = 0;
    long long int maxCnt = 0;
    for(int i=advTime - 1; i <= playTime; i++){
        long long int tmpCnt = subSum[i] - (i >= advTime ? subSum[i-advTime] : 0);
        if(maxCnt >= tmpCnt) continue;
        maxCnt = tmpCnt;
        answer = i-advTime+1;
    }
    return getString(answer);
}
