/**
 * problem: https://leetcode.com/problems/group-anagrams/
 * time complexity: O(N MlogM) // N = |strs|, M = |strs[i]|
 * data structure: Map
 */
 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m; // key: ordered strs[i], value: original strs[i] array
        for(int i=0;i<strs.size();i++){
            string now = strs[i];
            sort(now.begin(), now.end());
            m[now].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for(map<string, vector<string>>::iterator it = m.begin(); it != m.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
