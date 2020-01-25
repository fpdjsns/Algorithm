/**
 * problem: https://leetcode.com/problems/remove-covered-intervals/
 * time complexity: O(NlogN)
 */

class Solution {
private:
     static bool compare(const vector<int>& a,const vector<int>& b) {
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int size = intervals.size();
        int delCnt = 0;
        int last = -1;
        
        for(int i=0; i<size; i++){
            int now = intervals[i][1];
            if(last >= now) delCnt++;
            last = max(last, now);
        }
        return size - delCnt;
    }
};
