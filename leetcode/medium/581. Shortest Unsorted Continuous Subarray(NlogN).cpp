/**
 * problem : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 * time complexity : O(NlogN)
 */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int,int>> copied(n);
        for(int i = 0; i<n; i++) {
            copied[i] = {nums[i], i};
        }
        
        sort(copied.begin(), copied.end());
        
        int left = n;
        int right = n;
        for(int i = 0; i < n; i++) {
            int num = copied[i].first;
            int index = copied[i].second;
            
            if(num == nums[i]) continue;
            
            if(left == n) left = i;
            else right = i;
        }
        return left == right ? 0 : right-left+1;
    }
};
