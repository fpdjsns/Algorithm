/**
 * problem : https://leetcode.com/problems/dungeon-game/
 * algorithm : DP
 * time complexity : O(NM)
 * 참고 : https://www.youtube.com/watch?time_continue=1&v=JXBwuL4pL4o&feature=emb_logo
 */

class Solution {
    vector<vector<int>> dp;
    int n, m;
    // dp[x][y] = dungeon[x][y] -> dungeon[m-1][n-1]까지 이동할 때 필요한 최소 체력
    int solve(vector<vector<int>>& dungeon, int x, int y) {
        if(x == m-1 && y == n-1) return 1 + max(0, -dungeon[x][y]);
        if(x >= m || y >= n) return 1e9; // impossible
        
        int& ret = dp[x][y];
        if(ret != 1e9) return ret;
        
        ret = min(solve(dungeon, x+1, y), solve(dungeon, x, y+1)) - dungeon[x][y];
        return ret = max(1, ret); // 필요 체력은 1보다 커야한다.
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, 1e9));
        return solve(dungeon, 0, 0);
    }
};
