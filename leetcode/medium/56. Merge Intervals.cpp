/**
 * problem : https://leetcode.com/problems/merge-intervals/
 * time complexity : O(NlogN)
 * algorithm : greedy
 */
 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            // can't merge
            if(intervals[i][0] > end) {
                answer.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else { // can merge
                // update end
                end = max(end, intervals[i][1]);
            }
        }
        answer.push_back({start, end});
        
        return answer;
    }
};
