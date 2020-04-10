/**
 * problem : https://www.acmicpc.net/problem/1787
 * algorithm : KMP + DP
 * time complexity : O(N)
 */
 
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string.h>
#define MAX 1e9

using namespace std;

vector<int> dp;
vector<int> pi;

vector<int> makePi(string s) {
	vector<int> pi(s.size(), 0);
	int ind = 0;
	for (int i = 1; i < s.size(); i++) {
		while (ind > 0 && s[ind] != s[i])
			ind = pi[ind - 1];
		if (s[ind] == s[i])
			pi[i] = ++ind;
	}
	return pi;
}

int dfs(int ind) {
	if (ind < 0 || pi[ind] == 0) // not same
		return MAX;

	int& ret = dp[ind];
	if (ret != -1) return ret;
	ret = min(pi[ind], dfs(pi[ind] - 1));
	return ret;
}

long long int solve(int N, string s) {
	pi = makePi(s);
	dp = vector<int>(N, -1);
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += max(0, i - dfs(i) + 1);
	}
	return ans;
}

int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	cout << solve(N, s) << endl;
	return 0;
}
