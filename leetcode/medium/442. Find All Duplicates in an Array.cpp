/**
 * problem : https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * time complexity : O(N)
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int ind = 0;
        while(ind < nums.size()) {
            int num = nums[ind];
            if(num == ind + 1) {
                ind++;
                continue;
            }
            
            swap(nums[num-1], nums[ind]);
            if(nums[num-1] == nums[ind])
                ind++;
        }
        
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i+1) 
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
