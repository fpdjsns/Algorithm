/**
 * problem : https://leetcode.com/problems/3sum-with-multiplicity/
 * time complexity : O(NM) // N = |arr|, M = target
 * space complexity : O(M)
 * algorithm : knapsack
 */
 
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        
        // dp[target][cnt] = cnt개의 수를 더해서 target을 만들 수 있는 경우의 수.
        vector<vector<int>> dp(target+1, vector<int>(4));
        dp[0][0] = 1; // 0개의 수를 더하면 0
        
        for(auto num: arr){
            for(int t=target; t>=0; t--){
                for(int cnt=2; cnt>=0; cnt--){
                    // num + x = t
                    // x = t - num
                    if(t - num < 0) continue;
                    dp[t][cnt+1] = (dp[t][cnt+1] + dp[t-num][cnt]) % MOD;
                }
            }
        }
        
        return dp[target][3];
    }
};
