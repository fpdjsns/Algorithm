/**
 * problem : https://leetcode.com/problems/non-decreasing-array/
 * time complexity : O(N)
 */

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        int ind =-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<=nums[i+1]) continue;
            if(ind != -1) return false;
            ind = i;
        }
        return ind == -1 || ind == 0 || ind == n-2 || nums[ind-1] <= nums[ind+1] || nums[ind] <= nums[ind+2];
    }
};
