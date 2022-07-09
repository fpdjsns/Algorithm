/**
 * problem : https://leetcode.com/problems/jump-game-vi/
 * time complexity : O(N)
 * algorithm : Monotonic Queue
 */
 
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, -1e9); // dp[i] = i 위치에서 n-1 까지 갈 때의 최대 score
        deque<int> dq; // desc
        for(int i=n-1; i>=0; i--){
            while(!dq.empty() && dq.front() > i + k)
                dq.pop_front();
            dp[i] = (dq.empty() ? 0 : dp[dq.front()]) + nums[i];
            while(!dq.empty() && dp[i] > dp[dq.back()]) // set desc
                dq.pop_back();
            dq.push_back(i);
        }
        return dp[0];
    }
};
