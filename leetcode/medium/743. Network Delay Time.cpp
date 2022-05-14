/**
 * problem : https://leetcode.com/problems/network-delay-time/
 * time complexity : O(ElogE)
 * algorithm : BFS
 */
 
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto time: times) {
            adj[time[0]-1].push_back({time[1]-1, time[2]});
        }
        
        k--;
        vector<bool> check(n, false);
        int cnt = 0;
        int answer = -1;
        priority_queue<pair<int, int>> q;
        q.push({0, k}); // time, node
        while(!q.empty()){
            int now = q.top().second;
            int time = q.top().first * -1;
            q.pop();
            if(check[now]) continue;
            check[now] = true;
            answer = max(answer, time);
            cnt++;
            
            for(auto nextNode: adj[now]) {
                int next = nextNode.first;
                int nextTime = nextNode.second + time;
                q.push({nextTime * -1, next});
            }
        }
        return cnt == n ? answer : -1;
    }
};
