/**
 * problem : https://leetcode.com/problems/course-schedule-iii/
 * time complexity : O(NlogN)
 * algorithm : greedy
 */

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){
           if(a[1] == b[1]) return a[0] < b[0]; // duration asc
            return a[1] < b[1]; // lastDay asc
        });
        
        priority_queue<int> q; // durataion
        int day = 0;
        for(auto course: courses) {
            int newDay = day + course[0];
            int limitDay = course[1];
            if(newDay <= limitDay) { // possible
                q.push(course[0]);
                day += course[0];
            } else if(!q.empty() && newDay - q.top() < limitDay && course[0] < q.top()) { // change
                day -= q.top();
                q.pop();
                q.push(course[0]);
                day += course[0];
            }
        }
        
        return q.size();
    }
};
