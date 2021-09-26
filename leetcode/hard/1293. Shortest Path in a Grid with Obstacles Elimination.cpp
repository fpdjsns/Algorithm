/** 
 * problem : https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
 * time/space complexity : O(NMK)
 * algorithm : BFS
 */

class Solution {
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<bool>>>visits = vector<vector<vector<bool>>>(m, vector<vector<bool>>(n, vector<bool>(k+1, false)));
    
        queue<pair<pair<int,int>,pair<int,int>>> q;
        q.push({{0,0},{k, 0}});
        visits[0][0][k] = true;
        
        // bfs
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int k = q.front().second.first;
            int steps = q.front().second.second;
            q.pop();
            
            // find answer
            if(x == m-1 && y == n-1) 
                return steps;
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(visits[nx][ny][k]) continue;
                
                visits[nx][ny][k] = true;
                if(grid[nx][ny] == 1) {
                    if(k == 0) continue; //impossible
                    q.push({{nx, ny}, {k-1, steps+1}});
                } else {                
                    q.push({{nx, ny}, {k, steps+1}});
                }
            }   
        }
        
        return -1;
    }
};
    
