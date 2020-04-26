/**
 * problem : https://leetcode.com/problems/jump-game-ii/
 * algorithm : greedy
 * time complexity : O(N)
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxInd = 0;
        int tmp = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            maxInd = max(maxInd, i + nums[i]);
            if(tmp == i && i != nums.size() - 1) {
                ans++;
                tmp = maxInd;
            }
        }
        return ans;
    }
};
