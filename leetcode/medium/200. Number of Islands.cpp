/**
 * problem : https://leetcode.com/problems/number-of-islands/
 * time complexity : O(NM)
 * algorithm : DFS
 */

class Solution {
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    void setZeroWhenConnecting(vector<vector<char>>& grid, int x, int y) {
        if(x < 0 || x >= grid.size()) return;
        if(y < 0 || y >= grid[x].size()) return;
        if(grid[x][y] == '0') return;
        grid[x][y] = '0';
        for(int i=0;i<4;i++) {
            setZeroWhenConnecting(grid, x + dx[i], y + dy[i]);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '0') continue;
                ans++;
                setZeroWhenConnecting(grid, i, j);
            }
        }
        return ans;
    }
};
