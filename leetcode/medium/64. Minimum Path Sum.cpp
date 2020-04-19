/**
 * problem : https://leetcode.com/problems/minimum-path-sum/
 * algorithm : dfs
 * time complexity : O(nm)
 */
 
class Solution {
	vector<vector<int>> dp;
	int MAX_SUM = 1e9;
	int m, n;
	int dx[2] = { 1, 0 };
	int dy[2] = { 0, 1 };

	int minPathSum(int x, int y, vector<vector<int>>& grid) {
		int& ret = dp[x][y];
		if (ret != -1) return ret;
		int now = grid[x][y];
		ret = MAX_SUM;
		if (x == m - 1 && y == n - 1) return ret = now;

		for (int i = 0; i<2; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			ret = min(ret, now + minPathSum(nx, ny, grid));
		}

		return ret;
	}
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0) return 0;
		m = grid.size();
		n = grid[0].size();
		dp = vector<vector<int>>(m, vector<int>(n, -1));
		int ans = minPathSum(0, 0, grid);
		return ans;
	}
};
