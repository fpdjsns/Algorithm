/**
 * problem : https://leetcode.com/problems/binary-search/
 * time complexity : O(logN)
 * algorithm : binary search
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int m = 0;
        int left = 0;
        int right = n-1;
        
        while(left <= right){
            m = (left + right) / 2;
            if(nums[m] == target) return m;
            if(nums[m] < target) left = m+1;
            else right = m-1;
        }
        return -1;
    }
};
