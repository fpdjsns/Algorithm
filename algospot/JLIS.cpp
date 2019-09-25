/*
 * 문제 : https://www.algospot.com/judge/problem/read/JLIS
 * 시간복잡도 : O(NM(N+M))
 * 알고리즘 : DP
 */
 
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int N, M;
vector<int> A;
vector<int> B;
vector<vector<int>> dp;
long long MIN = LLONG_MIN;

/*
 * 시간복잡도 : O(NM(N+M))
 */

// A[indA], B[indB]를 시작점으로 하는 LIS 최대 길이.
// indA, indB는 항상 포함한다고 가정.
int solve(int indA, int indB) {
	if (N <= indA || M <= indB) return -1; // 범위를 벗어나는 경우 불가능 반환(-1)
	int& ret = dp[indA + 1][indB + 1];
	if (ret != -1) return ret;
	ret = 2;

	// 인덱스가 -1인 경우(시작) -> 최소값으로 세팅. 
	long long a = (indA == -1) ? MIN : A[indA];
	long long b = (indB == -1) ? MIN : B[indB];

	// a, b는 항상 포함이므로 두 개의 최대값 보다 큰 값만이 배열에 추가될 수 있다.
	long long maxNum = max(a, b); 

	for (int i = indA + 1; i < N; i++) {
		if (maxNum >= A[i]) continue;
		ret = max(ret, solve(i, indB) + 1); // +1 은 indA의 길이
	}
	for (int i = indB + 1; i < M; i++) {
		if (maxNum >= B[i]) continue;
		ret = max(ret, solve(indA, i) + 1); // +1 은 indB의 길이
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> N >> M;

		A = vector<int>(N);
		B = vector<int>(M);
		dp = vector<vector<int>>(N + 1, vector<int>(M + 1, -1));

		for (int i = 0; i < N; i++) cin >> A[i];
		for (int i = 0; i < M; i++) cin >> B[i];

		// A[-1], B[-1]을 항상 포함한다고 가정했으므로 2개의 길이를 빼줌.(-2).
		cout << solve(-1, -1) - 2 << endl; 
	}
	return 0;
}
