/**
 * problem : https://leetcode.com/problems/perfect-squares/
 * time complexity : O(NlogN)
 * algorithm : DP
 */

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 1e9);
        
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j*j <= i; j++){
                int perfect = j*j;
                dp[i] = min(dp[i], dp[i-perfect] + 1);
            }
        }
        return dp[n];
    }
};
