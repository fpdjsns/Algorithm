/**
 * problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc
 */

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int MOD = 1e9;
// E W N S
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void move(int& x, int& y, char now, long long int mul) {

	int ind = 0;
	switch (now) {
	case 'E': ind = 0; break;
	case 'W': ind = 1; break;
	case 'N': ind = 2; break;
	case 'S': ind = 3; break;
	}

	x = (x + dx[ind] * mul + MOD) % MOD;
	y = (y + dy[ind] * mul + MOD) % MOD;
}
pair<int, int> solve(string s) {
	pair<int, int> ans = { 0, 0 };

	long long int mul = 1;
	vector<long long> nums;
	for (int i = 0; i < s.size(); i++) {
		char now = s[i];
		if ('2' <= now && now <= '9') {
			mul = mul * (now - '0') % MOD;
			nums.push_back(now - '0');
		}
		else if (now == '(') {
			continue;
		}
		else if (now == ')') {
			mul = 1;
			for (int i = 0; i < nums.size() - 1; i++)
				mul = mul * nums[i] % MOD;
			nums.pop_back();
		}
		else {
			move(ans.first, ans.second, now, mul);
		}
	}
	return { ans.first + 1, ans.second + 1 };
}

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		string s;
		cin >> s;
		pair<int, int> ans = solve(s);
		printf("Case #%d: %d %d\n", tc, ans.first, ans.second);
	}

	return 0;
}
