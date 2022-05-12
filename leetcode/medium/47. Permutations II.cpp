/**
 * problem : https://leetcode.com/problems/permutations-ii/
 * time complexity : O(N^2)
 * algorithm : backtracking
 */
 
class Solution {
    set<vector<int>> ansSet;
    int n;
    void set(int cnt, vector<int>& nums, vector<int>& array, vector<bool>& check) {
        if(cnt == n) {
            ansSet.insert(array);
            return;
        }
        for(int i=0; i<n; i++){
            if(check[i]) continue;
        
            check[i] = true;
            array.push_back(nums[i]);
            
            set(cnt+1, nums, array, check);
            
            array.pop_back();
            check[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ansSet.clear();
        n = nums.size();
        
        vector<int> array;
        vector<bool> check(n, false);
        
        set(0, nums, array, check);
        
        vector<vector<int>> answer;
        for(auto tmp: ansSet) {
            answer.push_back(tmp);
        }
        return answer;
    }
};
