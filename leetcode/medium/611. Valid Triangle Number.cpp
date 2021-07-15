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
            if(nums[i] == 0) continue;
            int right = i+2;
            for(int left=i+1; left<n-1; left++){
                if(nums[left] == 0) continue;
                right = max(right, left+1);
                while(right < n && nums[right] < nums[i] + nums[left]) right++;
                answer += right - left - 1;
            }
        }
        return answer;
    }
};
