/**
 * problem : https://leetcode.com/problems/valid-triangle-number/
 * time complexity : O(N^2)
 * algorithm : two-pointer
 */

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int answer = 0;
        for(int i=0; i<n; i++){
            int right = i+2;
            for(int left=i+1; left<n-1; left++){
                while(right < n && nums[right] < nums[i] + nums[left]) right++;
                answer += max(0, right - left - 1);
            }
        }
        return answer;
    }
};
