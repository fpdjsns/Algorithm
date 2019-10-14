/*
 * 문제 : https://leetcode.com/problems/path-with-maximum-gold/
 * 시간복잡도 : O((NM)^3)
 * 알고리즘 : DFS
 */
 
class Solution {
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    int ans =0;
    
    void dfs(int x, int y, int sum, vector<vector<int>> grid) {
        sum += grid[x][y];
        grid[x][y] = 0;
        ans = max(ans, sum);
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
            if(grid[nx][ny] == 0) continue;
            
            dfs(nx, ny, sum, grid);
        }
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 0) continue;
                dfs(i, j, 0, grid);
            }
        }
        
        return ans;
    }
};
