/**
 * problem : https://leetcode.com/problems/partition-equal-subset-sum/
 * algorithm : DP
 * time complexity : O(NM) // N = |nums|, M = sum(nums)/2
 */
 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums) sum += num;
        if(sum % 2 == 1) return false;
        sum /= 2;
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1, false));
        dp[0][0] = true;
        for(int i=1;i<dp.size();i++){
            dp[i][0] = true;
            int num = nums[i-1];
            for(int j=num;j<dp[i].size();j++){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-num];
            }
        }
        
        return dp[nums.size()][sum];
    }
};
