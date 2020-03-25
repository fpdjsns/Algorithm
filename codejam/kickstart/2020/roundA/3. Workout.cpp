/**
 * problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f5b
 * time complexity : O(NlogM) // M = max(M[i]), 1e9
 * algorithm : Bisection(이진 탐색)
 */

#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

int solve(int N, int K, vector<int> M) {
	int l = 0;
	int r = 1e9;
	while (r - l > 1) {
		int m = (l + r) / 2; // let, difficulty
		int cnt = 0;
		for (int i = 1; i < M.size(); i++) {
			int diff = M[i] - M[i - 1];
			cnt += (diff - 1) / m;
		}
		if (cnt <= K) r = m; // possible
		else l = m; // impossible
	}
	return r;
}

int main() {
	int T;
	cin >> T;
	int N, K;
	for (int c = 1; c <= T; c++) {
		cin >> N >> K;
		vector<int> M(N, 0);
		for (int i = 0; i < N; i++) cin >> M[i];
		cout << "Case #" << c << ": " << solve(N, K, M) << endl;
	}

	return 0;
}
