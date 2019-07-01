/*
 * 문제 : https://algospot.com/judge/problem/read/ASYMTILING
 * 시간복잡도 : O(N)
 * 알고리즘 : DP
 */


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int MOD = 1000000007;

vector<int> dp;

int getAll(int n) {
	if (n <= 1) return dp[n] = 1;
	int& ret = dp[n];
	if (ret != -1) return ret;
	ret = (getAll(n - 1) + getAll(n - 2)) % MOD;
	return ret;
}

int getSymmetry(int n) {
	int ans = dp[n / 2];
	if (n % 2 == 0)
		ans = (ans + dp[n / 2 - 1]) % MOD;
	return ans;
}

int main() {
	int C;
	cin >> C;
	dp = vector<int>(101, -1);

	while (C--) {
		int N;
		cin >> N;

		int answer = (getAll(N) + MOD - getSymmetry(N)) % MOD;
		cout << answer << endl;
	}
	return 0;
}