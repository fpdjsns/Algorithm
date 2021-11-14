/** 
 * problem : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * timc complexity : O(logN)
 * algorithm : binary search
 */

 class Solution {    
    int binarySearch(vector<int>& nums, int target, bool isLeft) {
        int left = 0;
        int right = nums.size() - 1;
        int m = -1;
        int answer = -1;
        while(left <= right) {
            m = (left + right) / 2;

            bool isFind = false;
            if(nums[m] == target) {
                answer = m;
                isFind = true;
            }
            
            if((isFind && isLeft) || nums[m] > target) right = m - 1;
            if((isFind && !isLeft) || nums[m] < target) left = m + 1;
        }
        return answer;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums, target, true), binarySearch(nums, target, false)};
    }
};
