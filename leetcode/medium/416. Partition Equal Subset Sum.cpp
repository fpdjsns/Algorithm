/**
 * problem : https://leetcode.com/problems/partition-equal-subset-sum/
 * algorithm : DP
 * time complexity : O(NM) // N = |nums|, M = sum(nums)/2
 */
 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() < 2) return false;
        int sum = 0;
        for(auto num : nums) sum += num;
        if(sum % 2 == 1) return false;
        sum /= 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(int i=1;i<nums.size();i++){
            int num = nums[i-1];
            for(int j=sum;j>=num;j--){
                dp[j] = dp[j] || dp[j-num];
            }
        }
        return dp[sum];
    }
};
