/**
 * problem: https://algospot.com/judge/problem/read/NERD2
 * time complexity: O(NlogN)
 */

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solve(vector<pair<int, int>> arr) {
	int N = arr.size();

	int ans = 0;
	map<int, int> m; // (x,y)
	for (int i = 0; i < N; i++) {
		int p = arr[i].first;
		int q = arr[i].second;

		map<int, int>::iterator it = m.lower_bound(p);
		bool canNerd = (it == m.end()) || q > it->second;
		if (!canNerd) {
			ans += m.size();
			continue;
		}

		it = m.lower_bound(p);
		if (it != m.begin()) {
			--it;
			while (1) {
				if (it->second > q) break;

				map<int, int>::iterator tmp = it;
				--tmp;
				bool willBeEnd = it == m.begin();
				m.erase(it);
				if (willBeEnd) break;
				it = tmp;
			}
		}
		
		m[p] = q;
		ans += m.size();
	}

	return ans;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int N; cin >> N;
		vector<pair<int, int>> arr(N);
		for (int i = 0; i < N; i++) {
			cin >> arr[i].first >> arr[i].second;
		}
		cout << solve(arr) << endl;
	}
	return 0;
}
