/**
 * problem : https://leetcode.com/problems/largest-perimeter-triangle/
 * time complexity : O(N)
 */
 
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int answer = 0;
        for(int i=n-3; i>=0; i--){
            if(nums[i]+nums[i+1]<=nums[i+2]) continue;
            answer = nums[i] + nums[i+1] + nums[i+2];
            break;
        }
        
        return answer;
    }
};
