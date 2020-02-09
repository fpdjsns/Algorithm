/**
* problem: https://algospot.com/judge/problem/read/PALINDROMIZE
* time complexity: O(N + M)
* data structure: string
* algorithm : KMP
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> getPi(string s) {
	int size = s.size();
	vector<int> pi(size, 0);
	for (int i = 1; i < size; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[j] != s[i]) j = pi[j - 1];
		if (s[i] == s[j]) pi[i] = ++j;
	}
	return pi;
}

int getSameInd(string s, string p) {
	int N = s.size();
	vector<int> pi = getPi(p);

	int ans = 0;
	int start = 0;
	int sameInd = 0;
	while (start < N) {
		if (sameInd < p.size() && s[start + sameInd] == p[sameInd]) {
			sameInd++;
			if (sameInd + start == N) return sameInd;
		}
		else {
			if (sameInd == 0) {
				start++; continue;
			}
			int lastSameInd = pi[sameInd - 1];
			start += sameInd - lastSameInd;
			sameInd = lastSameInd;
		}
	}
}

int solve(string s) {
	string p = s;
	reverse(p.begin(), p.end());

	int N = s.size();
	int ans = getSameInd(s, p);
	return N + (N - ans);
}

int main() {
	int C;
	cin >> C;

	string s;
	while (C--) {
		cin >> s;
		cout << solve(s) << endl;
	}

	return 0;
}
