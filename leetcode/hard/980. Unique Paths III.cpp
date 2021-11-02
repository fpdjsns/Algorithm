/**
 * problem : https://leetcode.com/problems/unique-paths-iii/
 * algorithm : back tracking
 */

class Solution {
    
    int m, n;
    int total;
    int answer = 0;
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    void dfs (vector<vector<int>>& grid, vector<vector<bool>>& visit, int x, int y, int cnt) {
        if(grid[x][y] == 2) {
            answer += (cnt == total);
            return;
        }
        
        visit[x][y] = true;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(visit[nx][ny] || grid[nx][ny] == -1) continue;
            dfs(grid, visit, nx, ny, cnt+1);
        }
        
        visit[x][y] = false;
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        answer = 0;
        total = 1; // include end point
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        pair<int, int> start = {0, 0};
        
        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                total += (grid[i][j] == 0);
                if(grid[i][j] == 1) 
                    start = {i, j};
            }
        }
        cout << total << endl;
        
        visit[start.first][start.second] = true;
        dfs(grid, visit, start.first, start.second, 0);
        
        return answer;
    }
};
