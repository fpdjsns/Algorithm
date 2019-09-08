/*
 * 문제 : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
 * 시간복잡도 : O(d*f*target)
 * 알고리즘 : DP
 */
 
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        // dp[d][sum] = d개의 dice로 sum을 만들 수 있는 경우의 수
        vector<vector<int>> dp(d+1,vector<int>(target+1,0));
        int MOD = 1e9 + 7;
        
        // init
        for(int i=1; i<=min(f, target); i++)
            dp[1][i] = 1;
        
        // set dp array
        for(int dice=2;dice<=d;dice++){
            for(int sum = 0; sum <= target; sum++){
                for(int face=1; face<=f; face++){
                    if(sum-face < 0) break;
                    dp[dice][sum] = (dp[dice][sum] + dp[dice-1][sum-face]) % MOD;                
                }
            }
        }
        
        return dp[d][target];
    }
};
