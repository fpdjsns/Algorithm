/**
 * problem : https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/
 * algorithm : DP
 *
 * let) M = piles[i].length
 * time complexity : O(NM)
 * space complexity : O(NM + NK)
 */
 
class Solution {
    int getAns(vector<vector<int>>& sum, vector<vector<int>>& dp, int coins, int pileInd) {
        if(coins <= 0 || pileInd <= 0) return 0;
        
        int& ret = dp[coins][pileInd];
        if(ret != -1) return ret;
        ret = 0;

        for(int coin = 0; coin <= min((int)sum[pileInd].size()-1, coins); coin++){
            ret = max(ret, sum[pileInd][coin] + getAns(sum, dp, coins-coin, pileInd-1));
        }
        return ret;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        vector<vector<int>> sum(n+1);
        for(int i=1; i<=n; i++){
            sum[i] = vector<int>(piles[i-1].size()+1, 0);
            for(int j=1; j<=piles[i-1].size(); j++){
                sum[i][j] = sum[i][j-1] + piles[i-1][j-1];
            }
        }
        return getAns(sum, dp, k, n);
    }
};
