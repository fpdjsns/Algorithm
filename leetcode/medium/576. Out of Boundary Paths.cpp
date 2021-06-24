/**
 * problem : https://leetcode.com/problems/out-of-boundary-paths/
 * algorithm : DP
 * time complexity : O(maxMove * m * n)
 */
 
class Solution {
    int MOD = 1000000007;
    vector<vector<vector<int>>> dp;
    int getCnt(int m, int n, int maxMove, int x, int y) {
        if(x < 0 || x >= m || y < 0 || y >= n) return 1;
        int& ret = dp[maxMove][x][y];
        if(ret != -1) return ret;
        maxMove--;
        if(maxMove < 0) return ret = 0;
        return ret = 
            ((getCnt(m, n, maxMove, x-1, y)+ getCnt(m, n, maxMove, x+1, y)) % MOD
            + (getCnt(m, n, maxMove, x, y-1) + getCnt(m, n, maxMove, x, y+1)) % MOD 
                      ) % MOD;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp = vector<vector<vector<int>>>(maxMove+1, vector<vector<int>>(m, vector<int>(n, -1)));
        return getCnt(m,n,maxMove, startRow, startColumn);
    }
};
