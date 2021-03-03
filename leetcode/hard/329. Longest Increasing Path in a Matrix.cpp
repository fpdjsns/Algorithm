/**
 * problem : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
 * time complexity : O(nm)
 * algorithm : dfs, dp
 */
 
class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    vector<int> maxDist;
    vector<vector<int>> adj;
    
    int getDist(int now) {
        
        int& dist = maxDist[now];
        if(dist != -1) return dist;
        dist = 1;
        
        for(int next: adj[now]) {
            dist = max(dist, getDist(next) + 1);
        }
        return dist;
    }
        
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        adj = vector<vector<int>>(m*n);
        maxDist = vector<int>(m*n, -1);
        
        // set adj array
        for(int x=0; x<m; x++){
            for(int y=0; y<n; y++){
                int now = matrix[x][y];
                cout<<x*n + y<<" : ";
                for(int k=0; k<4;k ++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || nx >= m || ny < 0 || ny >=n) continue;
                    int next = matrix[nx][ny];
                    if(next <= now) continue;
            
                    adj[x*n + y].push_back(nx*n + ny);
                }
                cout << endl;
            }
        }
        
        int answer = 0;
        for(int i=0; i<adj.size(); i++) {
            answer = max(answer, getDist(i));
        }
        return answer;
    }
};
