/**
 * problem : https://leetcode.com/problems/unique-paths/
 * algorithm : DP, dfs
 * time complexity : O(NM)
 */

class Solution {
    int N, M;
    vector<vector<int>> dp;
    int go(int x, int y){
        if(x == M-1 && y == N-1)
            return 1;
        if(x >= M || y >= N)
            return 0;
        
        int& ret = dp[x][y];
        if(ret != -1) return ret;
        return ret = go(x+1, y) + go(x, y+1);
    }
public:
    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        return go(0, 0);
    }
};
