/**
 * problem : https://leetcode.com/problems/minimize-maximum-of-array/description/
 * time complexity : O(N)
 */

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long int sum = nums[0];
        int answer = nums[0];

        for(int i=1; i<nums.size(); i++){
            sum += nums[i];
            answer = max(answer, (int)((sum+i) / (i+1)));
        }
        return answer; 
    }
};
