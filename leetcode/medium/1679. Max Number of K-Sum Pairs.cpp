/**
 * problem : https://leetcode.com/problems/max-number-of-k-sum-pairs/
 * time complexity : O(NlogN)
 */
 
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;
        int answer = 0;
        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum == k) {
                answer++;
                left++;
                right--;
            } else if(sum < k) {
                left++;
            } else {
                right--;
            }
        }
        return answer;
    }
};
