/**
 * problem : https://leetcode.com/problems/shortest-path-in-binary-matrix/
 * time complexity : O(N^2)
 * algorithm : BFS
 */
 
class Solution {
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int answer = 1e9;
        int n = grid.size();
        
        if(grid[0][0] == 1)
            return -1;
        
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid.size(), false));
        visit[0][0] = true;
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{0,0}, 1});
        while(!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            
            if(x == n-1 && y == n-1) return dist;
            
            for(int i=0; i<dx.size(); i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(visit[nx][ny]) continue;
                if(grid[nx][ny] == 1) continue;
                
                visit[nx][ny] = true;
                q.push({{nx,ny}, dist+1});
            }
        }
        
        return -1;
    }
};
