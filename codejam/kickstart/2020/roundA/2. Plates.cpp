/**
 * problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb
 * time complexity : O(NPK)
 * algorithm : dp
 */

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

int N, K, P;
vector<vector<int>> arr;
vector<vector<int>> dp;

int dfs(int n, int p) {
	if (n >= N) return 0;
	int& ret = dp[n][p];
	if (ret != -1) return ret;
	ret = 0;
	int sum = 0;
	ret = dfs(n + 1, p);
	for (int i = 1; i <= K; i++) {
		if (p + i > P) break;
		sum += arr[n][i - 1];
		ret = max(ret, dfs(n+1, p + i) + sum);
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	for (int c = 1; c <= T; c++)  {
		cin >> N >> K >> P;
		int tmp;
		arr = vector<vector<int>>(N, vector<int>(K));
		dp = vector<vector<int>>(N, vector<int>(P + 1, -1)); // dp[i][j] = i:stack, j=Plate, dp[i][j] = maximum
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < K; j++) {
				cin >> arr[i][j];
			}
		}
		cout << "Case #" << c << ": " << dfs(0,0) << endl;
	}

	return 0;
}
