/**
 * problem : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b62
 * time complexity : O(logN). N = X + Y
 */
 
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <stack>
#include <stack>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

char LEFT = 'W';
char RIGHT = 'E';
char UP = 'N';
char DOWN = 'S';
void solve(int n, int m) {
	if ((n % 2 == 0 && m % 2 == 0) ||
		(m % 2 == 1 && n % 2 == 1)) {
		cout << "IMPOSSIBLE";
		return;
	}

	int sum = n > 0 ? n : -n;
	sum += m > 0 ? m : -m;

	int ind = 0;
	long long int mul = 1;
	while (sum > 0) {
		ind++;
		sum -= mul;
		mul *= 2;
	}
	
	string ans;
	while (mul > 1) {
		mul /= 2;
		int x = n > 0 ? n : -n;
		int y = m > 0 ? m : -m;
		if (x > y) { // row
			if (n > 0) {
				ans.push_back(DOWN);
				n -= mul;
			}
			else {
				ans.push_back(UP);
				n += mul;
			}
		}
		else { // column
			if (m > 0) {
				ans.push_back(LEFT);
				m -= mul;
			}
			else {
				ans.push_back(RIGHT);
				m += mul;
			}
		}
	}
	if (n != 0 || m != 0) {
		cout << "IMPOSSIBLE";
		return;
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
	
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		cout << "Case #" << tc << ": ";
		int n, m;
		cin >> n >> m;
		solve(-m, -n);
		cout << endl;
	}

	return 0;
}
