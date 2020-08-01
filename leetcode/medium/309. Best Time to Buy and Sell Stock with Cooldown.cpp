/**
 * problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 * time complexity : O(N^2)
 * algorithm : dp, dfs
 */
class Solution {
    vector<int> dp;
    int dfs(int startInd, const vector<int>& prices) {
        if(startInd >= prices.size())
            return 0;
        
        int& ret = dp[startInd];
        if(ret != -1) return ret;
        ret = 0;
        
        // don't buy stock[startInd]
        ret = dfs(startInd+1, prices);
        // buy stock[startInd] and sell
        for(int sellInd=startInd+1; sellInd<prices.size(); sellInd++){
            ret = max(ret, -prices[startInd] + prices[sellInd] + dfs(sellInd+2, prices));
        }
        
        return ret;
    }
public:
    int maxProfit(vector<int>& prices) {
        dp = vector<int>(prices.size(), -1);
        return dfs(0, prices);
    }
};
