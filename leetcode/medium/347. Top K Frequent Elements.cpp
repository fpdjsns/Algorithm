/**
 * problem : https://leetcode.com/problems/top-k-frequent-elements/
 * time complexity : O(NlogN)
 */
 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        for(auto num: nums) {
            cnts[num]++;
        }
        
        priority_queue<pair<int,int>> q;
        for(auto cnt: cnts){
            q.push({cnt.second, cnt.first});
        }
        
        vector<int> answer;
        while(k--){
            answer.push_back(q.top().second);
            q.pop();
        }
        return answer;
    }
};
