/**
 * problem : https://leetcode.com/problems/champagne-tower/
 * time complexity : O(N^2) // N = query_row
 * algorithm : DP
 */

class Solution {
public:
    
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 2, vector<double>(query_row + 2, 0L));
        dp[0][0] = poured;
        
        for(int row=0; row<=query_row; row++) {
            for(int glass=0; glass<=row; glass++){
                double now = dp[row][glass];
                
                if(now < 1) continue;
                dp[row+1][glass] += (now - 1) / 2L;
                dp[row+1][glass + 1] += (now - 1) / 2L;
                dp[row][glass] = 1L;
            }
        }
        
        
        return dp[query_row][query_glass];
    }
};
