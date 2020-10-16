/**
 * problem : https://leetcode.com/problems/rotate-array/
 * time complexity : O(2N)
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        k %= N;
        for(int i=0; i<N/2; i++) swap(nums[i], nums[N-1-i]);
        for(int i=0; i<k/2; i++) swap(nums[i], nums[k-1-i]);
        for(int i=k; i<k+(N-k)/2; i++) swap(nums[i], nums[N-1-i+k]);
    }
};
