/**
 * problem: https://algospot.com/judge/problem/read/RUNNINGMEDIAN
 * time complexity: O(NlogN)
 */

#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;

const int MOD = 20090711;

int solve(int N, int a, int b) {
	int ans = 0;

	int num = 1983;
	priority_queue<int> maxHeap; // left
	priority_queue<int> minHeap; // right
	for (int i = 0; i < N; i++) {
		if (maxHeap.size() == minHeap.size()) maxHeap.push(num);
		else minHeap.push(-num);
		
		if(!maxHeap.empty() && !minHeap.empty()){
			int left = maxHeap.top();
			int right = -minHeap.top();
			if (left > right) {
				maxHeap.pop(); minHeap.pop();
				maxHeap.push(right); minHeap.push(-left);
			}
		}
		ans = (ans + maxHeap.top()) % MOD;
		num = ((long long)num * a + b) % MOD;
	}
	return ans;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int N;
		cin >> N;
		int a, b;
		cin >> a >> b;
		cout << solve(N, a, b) << endl;
	}
	return 0;
}
