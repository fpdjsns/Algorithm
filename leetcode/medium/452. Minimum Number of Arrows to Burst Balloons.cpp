/**
 * problem : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 * time complexity : O(NlogN)
 */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        
        int answer = 1;
        pair<int,int> dupl = {points[0][0], points[0][1]};
        for(auto point: points) {
            int x = point[0];
            int y = point[1];
            if(dupl.second < x) {
                answer++;
                dupl = {point[0], point[1]};
            } else {
                dupl.first = max(dupl.first, point[0]);
                dupl.second = min(dupl.second, point[1]);
            }
        }
        
        return answer;
    }
};
