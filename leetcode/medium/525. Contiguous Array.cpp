/**
 * problem : https://leetcode.com/problems/contiguous-array/
 * data structure : map
 * time complexity : O(N)
 */
 
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> subSum;
        int sum = 0;
        int ans = 0;
        subSum[0] = 0;
        for(int i=1;i<=nums.size();i++){
            sum += nums[i-1] == 0 ? -1 : 1;
            if(subSum.find(sum) != subSum.end()){
                ans = max(ans, i - subSum[sum]);
            } else {
                subSum[sum] = i;
            }
        }
        return ans;
    }
};
