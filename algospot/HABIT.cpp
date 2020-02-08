/**
* problem: https://algospot.com/judge/problem/read/HABIT
* time complexity: O(N^2 * logN)
* data structure: string
* algorithm : Suffix Array
*/

#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// O(N * (lgN)^2)
vector<int> getSuffixArray(string s) {
	int size = s.size();
	vector<int> sa(size);
	for (int i = 0; i < size; i++) sa[i] = i;
	sort(sa.begin(), sa.end(), [s](int& a, int& b) {
		// compare s[~a], s[~b] 
		return strcmp(s.c_str() + a, s.c_str() + b) < 0;
	});
	return sa;
}

int solve(int K, string s) {
	vector<int> sa = getSuffixArray(s); // O(NlogN * N)

	int size = s.size();
	int ans = 0;

	// O(N^2)
	for (int i = 0; i <= size - K; i++) {
		int sameCnt = 0;
		int u = sa[i]; int v = sa[i + K - 1];
		while (u < size && v < size && s[u] == s[v]) {
			u++;v++;
			sameCnt++;
		}
		ans = max(ans, sameCnt);
	}

	return ans;
}

int main() {
	int C;
	cin >> C;

	int K; string s;
	while (C--) {
		cin >> K >> s;
		cout << solve(K, s) << endl;
	}

	return 0;
}
