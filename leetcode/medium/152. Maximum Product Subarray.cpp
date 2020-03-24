/**
 * problem : https://leetcode.com/problems/maximum-product-subarray/
 * time complexity : O(N)
 * algorithm : DP
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProducts = nums[0];
        int minProducts = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            int now = nums[i];
            int a = maxProducts * now;
            int b = minProducts * now;
            maxProducts = max(now, max(a, b));
            minProducts = min(now, min(a, b));
            ans = max(ans, maxProducts);
        }
        return ans;
    }
};
