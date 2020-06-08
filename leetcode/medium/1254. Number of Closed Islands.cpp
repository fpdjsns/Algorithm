/**
 * problem : https://leetcode.com/problems/number-of-closed-islands/
 * time complxity : O(NM)
 * algorithm : dfs, bfs
 */
class Solution {
    int n, m;
    void bfs(int x, int y, vector<vector<int>>& grid) {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        if(grid[x][y] == 1) return;
        queue<pair<int,int>> q;
        q.push({x, y});
        grid[x][y] = 1;
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n ||
                  ny < 0 || ny >= m) continue;
                if(grid[nx][ny] == 1) continue;
                grid[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        if(n == 0) return 0;
        m = grid[0].size();
        for(int i=0;i<m;i++){
            bfs(0, i, grid);
            bfs(n-1, i, grid);
        }
        for(int i=0;i<n;i++){
            bfs(i, 0, grid);
            bfs(i, m-1, grid);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) continue;
                ans++;
                bfs(i, j, grid);
            }
        }
        return ans;
    }
};
