/**
 * problem : https://leetcode.com/problems/search-insert-position/
 * time coplexity : O(NlogN)
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[n-1] < target) return n;
        
        int m;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            m = (left + right) / 2;
            if(nums[m] == target) return m;
            if(nums[m] < target) left = m+1;
            else right = m-1;
        }
        
        return left;
    }
};
