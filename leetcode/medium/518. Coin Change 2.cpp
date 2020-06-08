/**
 * problem : https://leetcode.com/problems/coin-change-2/
 * time complexity : O(NM). N = amount, M = |coins|
 * algorithm : DP
 */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i=1; i<=coins.size(); i++){
            int coin = coins[i-1];
            for(int j=coin; j<=amount; j++){
                dp[j] += dp[j-coin];
            }
        }
        return dp[amount];
    }
};
