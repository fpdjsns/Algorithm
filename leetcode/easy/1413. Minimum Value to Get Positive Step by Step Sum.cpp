/**
 * problem : https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
 * time complexity : O(N)
 */

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minSubSum = nums[0];
        int subSum = 0;
        for(auto num: nums){
            subSum += num;
            minSubSum = min(minSubSum, subSum);
        }
        return max(1, (minSubSum * -1)+1);
    }
};
