/**
 * problem : https://leetcode.com/problems/jump-game-iv/
 * time complexity : O(2N)
 * algorithm : DFS
 */

class Solution {
    vector<bool> visits;
public:
    int minJumps(vector<int>& arr) {
        int N = arr.size();
        visits = vector<bool>(N, false);
        map<int, vector<int>> sameMap;
        for(int i=0; i<N; i++){
            sameMap[arr[i]].push_back(i);
        }
        
        queue<pair<int,int>> q;
        q.push({0, 0});
        visits[0] = true;

        int answer = 0;
        while(!q.empty()){
            int index = q.front().first;
            int cnt = q.front().second;
            q.pop();
            
            if(index == N-1) { answer = cnt; break; }
            cnt++;
            
            for(auto sameIndex: sameMap[arr[index]]) {
                if(visits[sameIndex]) continue;
                q.push({sameIndex, cnt});
                visits[sameIndex] = true;
            }
            sameMap[arr[index]] = vector<int>();
            if(index + 1 < N && !visits[index + 1]) { q.push({index+1, cnt}); visits[index+1] = true; } 
            if(index - 1 >= 0 && !visits[index - 1]) { q.push({index-1, cnt}); visits[index-1] = true; }
        }
        
        return answer;
    }
};
