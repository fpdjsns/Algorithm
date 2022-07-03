/**
 * problem : https://leetcode.com/problems/wiggle-subsequence/
 * time complexity : O(N)
 * algorithm : greedy
 */

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int positive = 1;
        int negative = 1;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]) positive = negative + 1;
            if(nums[i] < nums[i-1]) negative = positive + 1;
        }
        
        return max(positive, negative);
    }
};
