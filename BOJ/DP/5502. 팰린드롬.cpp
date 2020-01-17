/*
 * 문제 : https://www.acmicpc.net/problem/5502
 * 시간복잡도 : O(N^2)
 * 알고리즘 : DP, LCS(Longest Common Subsequence)
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int N;
string s;

// dp[i][j] = s[~i] reverse_s[~j] 최장 공통 subsequence 길이
vector<vector<int>> dp;

int getLcs() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int c = s[i-1];
		for (int j = 1; j <= N; j++) {
			int reverse_c = s[N - j];
			if (c == reverse_c) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j-1], dp[i - 1][j]);
			ans = max(ans, dp[i][j]);
		}
	}
	return ans;
}

int main() {
	cin >> N;
	cin >> s;
	dp = vector<vector<int>>(N+1, vector<int>(N + 1, 0));
	cout << N - getLcs() << endl;
	return 0;
}
