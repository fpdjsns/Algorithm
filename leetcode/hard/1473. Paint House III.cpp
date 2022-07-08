/**
 * problem : https://leetcode.com/problems/paint-house-iii/
 * time complexity : O(N^2 * M * target)
 * algorithm : DP
 */

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, 1e9)));
        
        for(int j=0; j<n; j++) {
            if(houses[0] != 0 && houses[0] != j+1) continue;
            dp[0][j][0] = (houses[0] == j+1) ? 0 : cost[0][j];
        }
        
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<target; k++) {
                    for(int color = 0; color < n; color++){
                        int cnt = k - (color != j);
                        if(cnt < 0) continue;
                        if(houses[i] != 0 && houses[i] != j+1) continue;
                        int nowCost = (houses[i] == j+1) ? 0 : cost[i][j];
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][color][cnt] + nowCost);
                    }
                }
            }
        }
        
        int answer = 1e9;
        for(int j=0; j<n; j++){
            answer = min(answer, dp[m-1][j][target-1]);
        }
        return answer == 1e9 ? -1 : answer;
    }
};
