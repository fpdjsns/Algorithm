/**
 * problem : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f
 * time complexity : O(N)
 * algorithm : greedy
 */
 
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		string s;
		cin >> s;
		queue<pair<int, int>> q;

		string ans = "";
		int before = 0;
		for (int i = 0; i < s.size(); i++) {
			int now = s[i] - '0';
			if (now > before) {
				for (int i = 0; i < now - before; i++) {
					ans += '(';
				}
			}
			else if (now < before) {
				for (int i = 0; i < before - now; i++) {
					ans += ')';
				}
			}
			ans += now + '0';
			before = now;
		}
		for (int i = 0; i < before; i++)
			ans += ')';

		cout << "Case #" << tc << ": " << ans << endl;
	}

	return 0;
}
