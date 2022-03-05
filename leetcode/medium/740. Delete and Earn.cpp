/**
 * problem : https://leetcode.com/problems/delete-and-earn/
 * time complexity : O(N) // N = maximum of nums[i] 
 * algorithm : DP
 */
 
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> cnts(maxNum+1,0);
        for(auto num: nums) cnts[num]++;
        int answer = 0;
        vector<int> dp(maxNum+1, 0);
        dp[1] = cnts[1];
        for(int i=2; i<=maxNum; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + cnts[i]*i);
        }
        return dp[maxNum];
    }
};
