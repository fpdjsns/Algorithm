/**
 * problem : https://leetcode.com/problems/longest-harmonious-subsequence/
 * time complexity : O(N)
 */
 
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto num: nums) {
            m[num]++;
        }
        
        int answer = 0;
        for(auto ele: m) {
            int num = ele.first;
            int cnt = ele.second;
            
            if(m.find(num+1) == m.end()) continue;
            answer = max(answer, cnt + m[num+1]);
        }
        return answer;
    }
};
