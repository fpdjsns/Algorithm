/**
 * problems : https://leetcode.com/problems/house-robber/
 * time complexity : O(N)
 * algorithm : DP
 */

class Solution {
    vector<int> dp;
    int n;
    
    int go(vector<int>& nums, int ind) {
        if(ind >= n)
            return 0;
        int& ret = dp[ind];
        if(ret != -1) return ret;
        ret = 0;
        
        ret = max(go(nums, ind+2) + nums[ind],
                  go(nums, ind+1));
        
        return ret;
    }
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        dp = vector<int>(n, -1);
        return go(nums, 0);
    }
};
