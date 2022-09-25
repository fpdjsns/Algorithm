/**
 * problem : https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
 * time complexity : O(N)
 */

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int answer = 0;
        int n = nums.size();
        int cnt = 0;
        int maxNum = 0;
        for(int i=0; i<n; i++){
            if(nums[max(0, i-1)] == nums[i]) cnt++;
            else cnt = 1;
            
            if(nums[i] > maxNum){
                maxNum = nums[i];
                answer = cnt;
            }
            else if(nums[i] == maxNum){
                answer = max(answer,cnt);
            }
        }
        return answer;
    }
};
