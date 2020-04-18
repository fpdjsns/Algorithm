/**
 * problem : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
 * data structure : set
 * time complexity : O(N^2)
 */

#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		vector<vector<int>> arr(N, vector<int>(N));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];
		int k = 0, r = 0, c = 0;
		for (int i = 0; i < N; i++) {
			k += arr[i][i];
		}
    
		bool findR = false, findC = false;
		for (int i = 0; i < N; i++) {
			findR = false;
			findC = false;
			set<int> rSet, cSet;
			for (int j = 0; j < N; j++) {
				if (!findR && rSet.find(arr[j][i])!= rSet.end()) {
					findR = true; c++;
				}
				if (!findC && cSet.find(arr[i][j]) != cSet.end()) {
					findC = true; r++;
				}
				rSet.insert(arr[j][i]);
				cSet.insert(arr[i][j]);
			}
		}

		printf("Case #%d: %d %d %d\n", tc, k, r, c);
	}

	return 0;
}
