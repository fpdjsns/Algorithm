/**
 * problem : https://leetcode.com/problems/jump-game-iii/
 * time/space complexity : O(N)
 */

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visits(n, false);
        
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            
            if(visits[i]) continue;
            visits[i] = true;
            if(arr[i] == 0) return true;
            if(i + arr[i] < n && !visits[i + arr[i]]) q.push(i+arr[i]);
            if(i - arr[i] >= 0 && !visits[i - arr[i]]) q.push(i-arr[i]);
        }
        return false;
    }
};
