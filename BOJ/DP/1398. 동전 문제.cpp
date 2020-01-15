/*
 * 문제 : https://www.acmicpc.net/problem/1398
 * 시간복잡도 : O(NM) // N = 3, M = 99
 * 알고리즘 : DP
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> coins = { 1, 10, 25 };
vector<int> dp;

void init() {
	dp = vector<int>(100, 1e9);
	dp[0] = 0;
	for (int i = 0; i < coins.size(); i++) {
		int coin = coins[i];
		for (int j = 1; j < 100; j++) {
			if (j - coin >= 0) dp[j] = min(dp[j], dp[j - coin] + 1);
		}
	}
}

int solve(long long int money) {
	int ans = 0;
	while (money > 0) {
		ans += dp[money % 100];
		money /= 100;
	}
	return ans;
}


int main() {

	init();

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		long long int money;
		cin >> money;
		cout << solve(money) << endl;
	}
	return 0;
}
