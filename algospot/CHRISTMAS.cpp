/*
 * 문제 : https://algospot.com/judge/problem/read/CHRISTMAS
 * 시간복잡도 : O(N + K)
 * 알고리즘 : Partial sum
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define MOD 20091101

using namespace std;

int N, K;
vector<int> sum;

// O(N)
int getSecondAns() {

	vector<int> memCnt(N + 1, 0);
	vector<int> lastInd(K, -1);
	for (int i = 0; i <= N; i++) {
		int& ret = memCnt[i];
		if (0 < i)
			ret = memCnt[i - 1]; // 현재 상자 구입하지 않는 경우
		int cnt = sum[i]; // i 번 상자의 부분합

		int prevInd = lastInd[cnt]; // 이 전에 선택된 인덱스
		if (prevInd != -1) { // 이 전에 선택된 적 있으면 
			ret = max(memCnt[i], memCnt[prevInd] + 1); // 이 전 선택된 곳 ~ 현재 위치까지 구입 (1번 구입 추가)
		}
		lastInd[cnt] = i; // 구입 인덱스 갱신
	}
	return memCnt.back();
}

// O(N + K)
int getFirstAns() {
	map<int, int> m;
	for (int i = 0; i <= N; i++) {
		m[sum[i]]++;
	}

	int ans = 0;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		int cnt = it->second;
		if (cnt < 2) continue;
		ans = (ans + ((long long)cnt * (cnt - 1)) / 2) % MOD;
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		sum = vector<int>(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			cin >> sum[i];
			sum[i] = (sum[i] + sum[i - 1]) % K;
		}

		printf("%d %d\n", getFirstAns(), getSecondAns());
	}

	return 0;
}
