/**
 * problem : https://www.hackerrank.com/challenges/grid-challenge/problem
 * time complexity : O(N * MlogM) (let, arr = NxM)
 */

#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

string solve(vector<string> arr) {
	int N = arr.size();

	for (int i = 0; i < N; i++) {
		sort(arr[i].begin(), arr[i].end());
		if (i == 0) continue;
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] < arr[i - 1][j]) {
				return "NO";
			}
		}
	}

	return "YES";
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		scanf("%d", &N);
		vector<string> arr(N, string(N, ' '));
		for (int i = 0; i < N; i++) {
			char s[101];
			scanf("%s", s);
			arr[i] = string(s);
		}
		printf("%s\n", solve(arr).c_str());
	}
	return 0;
}
