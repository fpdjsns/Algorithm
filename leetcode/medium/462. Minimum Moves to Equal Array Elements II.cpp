/**
 * problem : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
 * time complexity : O(NlogN)
 */
 
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n/2];
        int answer = 0;
        for(auto num: nums) answer += abs(num - median);
        return answer;
    }
};
