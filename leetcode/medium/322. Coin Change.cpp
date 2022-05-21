/**
 * problem : https://leetcode.com/problems/coin-change/
 * time complexity : O(|coins| x |amount|)
 * algorithm : DP
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;
        for(int i=1; i<=coins.size(); i++){
            int coin = coins[i-1];
            for(int j=coin; j<=amount; j++){
                dp[j] = min(dp[j], dp[j-coin] + 1);
            }
        }
        int answer = dp[amount];
        return answer == 1e9 ? -1 : answer;
    }
};
