/**
 * problem : https://leetcode.com/problems/cherry-pickup-ii/
 * algorithm : DP
 * time complexity : O(NM^2)
 */

class Solution {
    vector<int> dy = {-1, 0, 1};
    vector<vector<vector<int>>> dp;
    int N, M;
    int go(vector<vector<int>>& grid, int row, int col1, int col2) {
        if(row == N) return 0;
        
        int& ret = dp[row][col1][col2];
        if(ret != -1) return ret;
        ret = 0;
        
        for(int i=0; i<3; i++){
            int ncol1 = col1 + dy[i];
            if(ncol1 < 0 || ncol1 >= M) continue;
            for(int j=0; j<3; j++){
                int ncol2 = col2 + dy[j];
                if(ncol2 < 0 || ncol2 >= M) continue;
                if(ncol1 == ncol2) continue;
                
                ret = max(ret, go(grid, row+1, ncol1, ncol2));
            }
        }
        
        return ret += grid[row][col1] + grid[row][col2];
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        dp = vector<vector<vector<int>>>(N, 
                                        vector<vector<int>>(M, vector<int>(M, -1)));
        
        return go(grid, 0, 0, M-1);
    }
};
