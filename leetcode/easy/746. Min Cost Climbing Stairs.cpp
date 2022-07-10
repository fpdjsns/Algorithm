/**
 * problem : https://leetcode.com/problems/min-cost-climbing-stairs/
 * time complexity : O(N)
 * algorithm : DP
 */
 
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2, 0);
        dp[1] = cost[0];
        dp[2] = cost[1];
        for(int i=3; i<= n+1; i++){
            dp[i] = min(dp[i-2], dp[i-1]) + (i <= n ? cost[i-1] : 0);
        }
        return dp[n+1];
    }
};
