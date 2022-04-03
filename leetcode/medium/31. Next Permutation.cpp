/**
 * problem : https://leetcode.com/problems/next-permutation/
 * time complexity : O(N)
 */
 
class Solution {
    void reverse(vector<int>& nums, int index) {
        int left = index;
        int right = nums.size()-1;
        while(left < right) {
            iter_swap(nums.begin() + (left++), nums.begin() + (right--));
        }
    }
    
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = n-1;
        while(index >= 0 && nums[index] >= nums[min(index+1, n-1)]) {
            index--;
        }
        if(index == -1) {
            reverse(nums, 0);
        } else{
            // nums[index] 보다 큰 값 중 가장 작은 값 찾기
            int minNumIndex = index+1;
            while(minNumIndex < n && nums[min(minNumIndex + 1, n-1)] > nums[index])
                minNumIndex++;
            iter_swap(nums.begin() + index, nums.begin() + min(n-1, minNumIndex));
            reverse(nums, index+1);
        }
    }
};
