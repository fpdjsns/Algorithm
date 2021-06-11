/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/42627
 * time complexity : O(NlogN)
 * data structure : priority queue
 */

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });
    int ind = 1;
    
    priority_queue<pair<int, int>> q;
    q.push({-1 * jobs[0][1], jobs[0][0]});
    
    long long sum = 0;
    int lastTime = 0;
    while(!q.empty()) {
        int duration = -1 * q.top().first;
        int startTime = q.top().second;
        q.pop();
        
        lastTime = max(lastTime, startTime) + duration;
        sum += lastTime - startTime;
        
        while(ind < n && (jobs[ind][0] <= lastTime || q.empty())) {
            q.push({-1 * jobs[ind][1], jobs[ind][0]});
            ind++;
        }
    }
    return sum / n;
}
