/**
 * problem : https://leetcode.com/problems/subsets-ii/
 * time complexity : O(N^2)
 * algorithm : backtracking
 */

class Solution {
    vector<vector<int>> answer;
    void backtracking(vector<int>& nums, int ind, vector<int>& subset) {
        answer.push_back(subset);
        if(ind >= nums.size()) return;
        
        int before = -20;
        for(int i=ind; i<nums.size(); i++) {
            if(before == nums[i]) continue;
            subset.push_back(nums[i]);
            backtracking(nums, i+1, subset);
            subset.pop_back();
            before = nums[i];
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        answer = vector<vector<int>>();
        sort(nums.begin(), nums.end());
        vector<int> subset;
        backtracking(nums, 0, subset);
        return answer;
    }
};
