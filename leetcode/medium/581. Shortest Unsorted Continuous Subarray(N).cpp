/**
 * problem : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 * time complexity : O(2N)
 */
 
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        
        int right = n;
        int maxNum = nums[0];
        for(int i=0; i<n; i++){
            if(nums[i] < maxNum) right = i; // unsorted
            maxNum = max(maxNum, nums[i]);
        }
        
        int left = 0;
        int minNum = nums[n-1];
        for(int i=n-1; i>=0; i--){
            if(nums[i] > minNum) left = i; // unsorted
            minNum = min(minNum, nums[i]);
        }
        
        // sorted
        if(right == n && left == 0) return 0;
        return right - left + 1;
    }
};
