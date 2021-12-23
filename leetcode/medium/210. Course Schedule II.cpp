/**
 * problem : https://leetcode.com/problems/course-schedule-ii/
 * time complexity : O(N+M). N = numCourses, M = |prerequisites|
 */
 
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> degree(numCourses);
        
        for(auto prerequisite: prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            degree[prerequisite[0]]++;
        }
        
        queue<int> q;
        for(int course=0; course<numCourses; course++){
            if(degree[course] == 0) q.push(course);
        }
        
        vector<int> answer;
        while(!q.empty()) {
            int course = q.front(); q.pop();
            answer.push_back(course);
            for(auto next: adj[course]) {
                degree[next]--;
                if(degree[next] == 0) q.push(next);
            }
        }
    
        return answer.size() == numCourses ? answer : vector<int>();
    }
};
