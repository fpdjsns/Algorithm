/*
 * 문제 : https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
 * 시간복잡도 : O(N)
 * 알고리즘 : DP
 */

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        
        // dp[0][i] = include i's index and contiguous max sum.
        // dp[1][i] = arr[i~] contiguous max sum when one element deleted. 
        vector<vector<int>> dp(2, vector<int>(arr.size()+2, -1e9));
                  
        int ans = -1e9;
        for(int i=arr.size()-1;i>=0;i--){
            int now = arr[i];
            dp[0][i] = max(now, now + dp[0][i+1]); // 자기자신만, 자기자신 + (i+1)부터 시작하는 contiguous max sum
            dp[1][i] = max(dp[0][i+1], now + dp[1][i+1]); // 자기자신제외, 자기자신 포함 
            ans = max(dp[0][i], ans);
            ans = max(dp[1][i], ans);
        }
        
        return ans;
    }
};
