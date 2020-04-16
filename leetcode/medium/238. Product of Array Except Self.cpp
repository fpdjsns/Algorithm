/**
 * problem : https://leetcode.com/problems/product-of-array-except-self/
 * time complexity : O(N)
 * algorithm : subsum
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for(int i=1;i<n;i++) ans[i] = ans[i-1] * nums[i-1]; // nums[0, i) multiple
        for(int i=n-2;i>=0;i--) nums[i] = nums[i+1] * nums[i]; // nums[i, n) multiple
        for(int i=0; i<n-1;i++) ans[i] = ans[i] * nums[i+1]; // nums[0, i) * nums[i+1, n) multiple
        return ans;
    }
};
