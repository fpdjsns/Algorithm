/**
 * problem : https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * time complexity : O(N)
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int ind = i;
            while(nums[ind] != ind+1) {
                swap(nums[ind], nums[nums[ind]-1]);
                ind = nums[ind];
            }
            for(int i=0;i<nums.size();i++){
                cout<<nums[i]<<", ";
            }
            cout<<endl;
        }
        
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i+1) 
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
