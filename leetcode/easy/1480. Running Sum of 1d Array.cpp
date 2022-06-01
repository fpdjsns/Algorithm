/**
 * problem : https://leetcode.com/problems/running-sum-of-1d-array/
 * time complexity : O(N)
 */

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 0);
        for(int i=0; i<n; i++){
            answer[i] = answer[max(0, i-1)] + nums[i];
        }
        return answer;
    }
};
