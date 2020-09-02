/**
 * problem : https://leetcode.com/problems/contains-duplicate-iii/
 * algorithm : two-pointer
 * time complexity : O(NlogN)
 */
 
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int,int>> numsWithIndex(nums.size());
        for(int i=0; i<nums.size(); i++){
            numsWithIndex[i] = {nums[i], i};
        }
        
        sort(numsWithIndex.begin(), numsWithIndex.end());
        
        int i = 0;
        int j = 1;
        for(i = 0; i<nums.size(); i++){
            int left = numsWithIndex[i].first;
            int leftIndex = numsWithIndex[i].second;
            
            for(j = max(j, i+1); j<nums.size();j++){
                int right = numsWithIndex[j].first;
                int rightIndex = numsWithIndex[j].second;
                if((long long)right - left > t) break; // impossible
                if(abs(rightIndex - leftIndex) <= k) 
                    return true;
            }
        }
        
        return false;
    }
};
