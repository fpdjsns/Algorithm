/**
 * problem : https://leetcode.com/problems/course-schedule/
 * algorithm : topological sort
 * time complexity : O(N + M)
 */
 
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> cntPreCourse(numCourses);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            pair<int,int> pre = {prerequisites[i][0], prerequisites[i][1]};
            adj[pre.second].push_back(pre.first);
            cntPreCourse[pre.first]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(cntPreCourse[i] > 0) continue;
            q.push(i);
        }
        
        int cnt = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            cnt++;
            for(int i=0;i<adj[course].size();i++){
                int nextCourse = adj[course][i];
                cntPreCourse[nextCourse]--;
                if(cntPreCourse[nextCourse] == 0)
                    q.push(nextCourse);
            }
        }
        return cnt == numCourses;
    }
};
