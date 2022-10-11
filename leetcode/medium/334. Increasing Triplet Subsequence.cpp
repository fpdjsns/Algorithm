/**
 * problem : https://leetcode.com/problems/increasing-triplet-subsequence/description/
 * time complexity : O(N)
 */

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        int minNum = nums[0];
        vector<bool> canAns(n, false);
        for(int i=0; i<n; i++){
            int num = nums[i];
            canAns[i] = num > minNum;
            minNum = min(num, minNum);
        }
        
        int maxNum = nums[n-1];
        for(int i=n - 1; i >= 0; i--) {
            int num = nums[i];
            if(num < maxNum && canAns[i])
                return true;
            maxNum = max(num, maxNum);
        }
        return false;
    }
};
