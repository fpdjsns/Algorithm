/** 
 * problem : https://leetcode.com/problems/subsets/
 * time complexity : O(N!)
 * algorithm : BFS
 */
 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        
        int n = nums.size();
        queue<pair<int, vector<int>>> q;
        q.push({0, vector<int>()});
        
        while(!q.empty()) {
            int ind = q.front().first;
            vector<int> path = q.front().second;
            q.pop();
            
            answer.push_back(path);
            if(ind == n) {
                continue;    
            }          
            for(int i = ind; i<n; i++){
                path.push_back(nums[i]);
                q.push({i+1, path});
                path.pop_back();
            }
        }
        
        return answer;
    }
};
