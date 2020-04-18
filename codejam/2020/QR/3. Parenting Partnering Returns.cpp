/**
 * problem : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9
 * time complexity : O(NlogN)
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
		int N;
		cin >> N;
		vector<pair<pair<int, int>, int>> arr(N);
		for (int i = 0; i < N; i++) {
			cin >> arr[i].first.first >> arr[i].first.second;
			arr[i].first.second = -arr[i].first.second;
			arr[i].second = i;
		}
		sort(arr.begin(), arr.end());

		string ans(N, ' ');
		int cEndTime = -1;
		int jEndTime = -1;
		bool isImpossible = false;
		for (int i = 0; i < N; i++) {
			int start = arr[i].first.first;
			int end = -arr[i].first.second;
			int ind = arr[i].second;

			if (start >= cEndTime) {
				ans[ind] = 'C';
				cEndTime = end;
			}
			else if(start >= jEndTime) {
				ans[ind] = 'J';
				jEndTime = end;
			}
			else {
				isImpossible = true;
				break;
			}
		}
		if (isImpossible) ans = "IMPOSSIBLE";
		cout << "Case #" << tc << ": " << ans << endl;
	}

	return 0;
}
