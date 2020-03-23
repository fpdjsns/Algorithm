/**
 * problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56
 * time complexity : O(NlogN)
 * algorithm : greedy
 */

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int c = 1; c <= T; c++)  {
		int N, B;
		cin >> N >> B;
		vector<int> arr(N);
		for (int i = 0; i < N; i++) cin >> arr[i];
		sort(arr.begin(), arr.end());
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] > B) break;
			ans++;
			B -= arr[i];
		}
		cout << "Case #" << c << ": " << ans << endl;
	}

	return 0;
}
