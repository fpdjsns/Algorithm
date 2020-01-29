/**
 * problem : https://algospot.com/judge/problem/read/ITES
 * data structure : queue
 * time complexity : O(N)
 */

#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

int solve(int K, int N) {
	long long int outsideSignal = 1983;
	long long int TMP = pow(2, 32);

	int ans = 0;

	int subSum = 0;
	int signal = 0;

	queue<int> signals;

	for (int last = 0; last < N; last++) {
		signal = outsideSignal % 10000 + 1;
		outsideSignal = ((long long int)outsideSignal * 214013 + 2531011) % TMP;
		
		signals.push(signal);
		subSum += signal;
		
		while(!signals.empty()) {
			if (subSum < K) break;
			if (subSum == K) ans++;
			
			int deletedSignal = signals.front();
			signals.pop();
			subSum -= deletedSignal;
		}
	}

	return ans;
}

int main() {
	int C;
	cin >> C;

	while (C--) {
		int K, N;
		cin >> K >> N;
		cout << solve(K, N) << endl;
	}
	return 0;
}
