/**
 * problem : https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
 * time complexity : O(N)
 */
 
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int dist = 0;
        for(auto num: nums) {
            if(num == 1) {
                if(dist > 0) return false;
                dist = k;
            } else {
                dist--;                
            }
        }
        return true;
    }
};
