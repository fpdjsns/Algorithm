/**
 * problem : https://leetcode.com/problems/k-inverse-pairs-array/
 * time complexity : O(NK)
 * algorithm : DP
 */
 
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            long long sum = 0;
            for(int j=0; j<=k; j++) {
                sum += dp[i-1][j];
                if(j - i >= 0)
                    sum -= dp[i-1][j-i];
                dp[i][j] = sum % (int)(1e9 + 7);
            }
        }
        return dp[n][k];
    }
};
