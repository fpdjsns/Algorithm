/**
 * problem : https://leetcode.com/problems/house-robber-ii/
 * time complexity : O(2N)
 * algorithm : DP
 */

class Solution {
    
    // dp[ind] = ans range nums[ind,]
    vector<int> dp;
    
    // nums[ind]
    int dfs(vector<int>& nums, int ind, int end) {
        if(ind >= end) return 0;
        
        int& ret = dp[ind];
        if(ret != -1) return ret;
        
        return ret = max(
            nums[ind] + dfs(nums, ind + 2, end), 
            dfs(nums, ind + 1, end)
        );
    }
    
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if(N == 1) return nums[0];
        
        dp = vector<int>(N, -1);
        int robZeroIndex = dfs(nums, 0, N-1); // rob zero
        
        dp = vector<int>(N, -1);
        int notRobZeroIndex = dfs(nums, 1, N); // not rob zero
        
        return max(robZeroIndex, notRobZeroIndex);
    }
};
