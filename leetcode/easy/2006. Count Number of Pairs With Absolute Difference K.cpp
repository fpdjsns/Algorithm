/**
 * problem : https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
 * time complexity : O(N^2)
 */

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int answer = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++){
                if(i == j) continue;
                answer += (abs(nums[i]-nums[j]) == k);
            }
        }
        return answer;
    }
};
