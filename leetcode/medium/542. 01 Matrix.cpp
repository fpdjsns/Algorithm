/**
 * problem : https://leetcode.com/problems/01-matrix/
 * algorithm : BFS
 * time complexity : O(NM)
 * space complexity : O(NM)
 */
 
class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int n = mat.size(); int m = mat[0].size();
        vector<vector<int>> answer = mat;
        vector<vector<bool>> visit(n, vector<bool>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1) continue;
                q.push({i, j});
                visit[i][j] = true;
            }
        }
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            int dist = answer[x][y];
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // out of boundary
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(visit[nx][ny]) continue;
                visit[nx][ny] = true;
                q.push({nx, ny});
                answer[nx][ny] = dist + 1;
            }
        }
        
        return answer;
    }
};
