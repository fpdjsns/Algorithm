/**
 * problem : https://leetcode.com/problems/subarray-sum-equals-k/
 * time complexity : O(N^2)
 * algorithm : subsum
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> subSum(nums.size()+1, 0);
        for(int i=0;i<nums.size();i++){
            subSum[i+1] = subSum[i] + nums[i];
        }
        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<i;j++){
                if(subSum[i]-subSum[j] == k)
                    ans++;
            }
        }
        return ans;
    }
};
