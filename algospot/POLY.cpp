
/*
 * 문제 : https://algospot.com/judge/problem/read/POLY
 * 시간복잡도 : O(N^3)
 * 알고리즘 : DP
 */

#include<iostream>
#include<vector>

using namespace std;

int MOD = 10000000;
vector<vector<int>> dp(101, vector<int>(101, -1));

int solve(int size, int N) {
	if (N == size) return 1;
	int& ret = dp[size][N];
	if (ret != -1) return ret;
	
	ret = 0;
	for (int next = 1; next <= N - size; next++) {
		int cnt = size + next -1;
		ret = (ret + cnt * solve(next, N - size)) % MOD;
	}
	return ret;
}

int main() {
	int C;
	cin >> C;

	while (C--) {
		int N;
		cin >> N;
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			ans = (ans + solve(i, N)) % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
