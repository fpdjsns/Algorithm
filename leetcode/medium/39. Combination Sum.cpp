/**
 * problem : https://leetcode.com/problems/combination-sum/
 * time complexity : O(NM) // N = |candidates|, M = target
 * algorithm : backtracking
 */

class Solution {
    vector<vector<int>> ans;
    
    void go(vector<int>& candidates, int ind, int target, vector<int>& arr) {
        if(target == 0) {
            ans.push_back(arr);
            return;
        }
        if(target < 0) return;
        for(int i=ind; i<candidates.size(); i++){
            int num = candidates[i];
            if(target < num) continue;
            
            arr.push_back(num);
            go(candidates, i, target - num, arr);
            arr.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans = vector<vector<int>>();
        vector<int> arr;
        go(candidates, 0, target, arr);
        return ans;
    }
};
