/**
 * problem: https://algospot.com/judge/problem/read/INSERTION
 * time complexity: O(N^2)
 */

#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solve(vector<int> arr) {
	int N = arr.size();
	vector<int> prevArr(N);
	set<int> s;
	vector<int> nums(N);
	for (int i = 1; i <= N; i++) {
		nums[i - 1] = i;
	}
	for (int i = N - 1; i >= 0; i--) {
		int move = arr[i];
		vector<int>::iterator original = nums.begin() + (i - move);
		prevArr[i] = *original;
		nums.erase(original);
	}
	return prevArr;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int N; cin >> N;
		vector<int> arr(N);
		for (int i = 0; i < N; i++) cin >> arr[i];
		vector<int> ans = solve(arr);
		for (int i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
