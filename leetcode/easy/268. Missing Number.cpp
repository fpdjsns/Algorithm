/**
 * problem : https://leetcode.com/problems/missing-number/
 * time complexity : O(N)
 * space complexity : O(1)
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num: nums) sum += num;
        return (n+1) * n / 2 - sum;
    }
};
