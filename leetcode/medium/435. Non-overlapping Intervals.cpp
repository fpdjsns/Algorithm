/**
 * problem : https://leetcode.com/problems/non-overlapping-intervals/
 * time complexity : O(NlogN)
 * algorithm : greedy
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        
        int deletedCnt = 0;
        int last = -1e9;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0] < last) deletedCnt++;
            else last = intervals[i][1];
        }
        return deletedCnt;
    }
};
