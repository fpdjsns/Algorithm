/**
 * problem : https://leetcode.com/problems/pacific-atlantic-water-flow/
 * time complexity : O(N^2)
 */
 
class Solution {
    vector<vector<int>> dp;
    int m, n;
    
    int dx[4] = {-1 , 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    /**
     * 0 : x 
     * 1 : Pacific
     * 2 : Atlantic
     * 3 : Pacific + Atlantic
     */
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited,
            int x, int y, int value) {
        
        if(visited[x][y]) return;
        visited[x][y] = true;
        dp[x][y] |= value;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(heights[x][y] > heights[nx][ny]) continue;
            dfs(heights, visited, nx, ny, value);
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) dfs(heights, visited, i, 0, 1);
        for(int i=0; i<n; i++) dfs(heights, visited, 0, i, 1);
        
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) dfs(heights, visited, i, n-1, 2);
        for(int i=0; i<n; i++) dfs(heights, visited, m-1, i, 2);
        
        vector<vector<int>> answer;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(dp[i][j] == 3) answer.push_back({i, j});
        
        return answer;
    }
};
