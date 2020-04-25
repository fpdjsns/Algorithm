/**
 * problem : https://leetcode.com/problems/jump-game/
 * algorithm : greedy
 * time complexity : O(N)
 */
 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canIndex = 0;
        for(int i=0; i<nums.size(); i++){
            if(canIndex < i) return false; // can not reached i
            canIndex = max(canIndex, i+nums[i]);
        }
        return true;
    }
};
