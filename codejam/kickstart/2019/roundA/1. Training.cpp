/**
 * problem : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e01/00000000000698d6
 * time complexity : O(NlogN)
 * algorithm : subsum
 */

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solve(vector<int> arr, int K) {
	int N = arr.size() - 1;
	sort(arr.begin(), arr.end());
	vector<int> subSum(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		subSum[i] = subSum[i - 1] + arr[i];
	}

	int ans = 1e9;
	for (int i = K; i <= N; i++) {
		int hours = (arr[i] * K) - (subSum[i] - subSum[i - K]);
		ans = min(ans, hours);
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	int N, K;
	for (int c = 1; c <= T; c++) {
		cin >> N >> K;
		vector<int> arr(N + 1, 0);
		for (int i = 1; i <= N; i++) cin >> arr[i];
		cout << "Case #" << c << ": " << solve(arr, K) << endl;
	}

	return 0;
}
