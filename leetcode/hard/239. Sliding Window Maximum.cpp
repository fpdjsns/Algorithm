/**
 * problem : https://leetcode.com/problems/sliding-window-maximum/
 * algorithm : sliding window
 * time complexity : O(NlogM) // N : |nums|, M : k
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;
        vector<int> answer;
        for(int i=0;i<nums.size();i++){
            q.push({nums[i], i});
            if(i<k-1) continue;
            while(!q.empty() && q.top().second <= i-k) q.pop();
            answer.push_back(q.top().first);
        }
        return answer;
    }
};
