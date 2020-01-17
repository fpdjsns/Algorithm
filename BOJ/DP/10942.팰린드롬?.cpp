/*
 * 문제 : https://www.acmicpc.net/problem/10942
 * 시간복잡도 : O(N^2)
 * 알고리즘 : DP
 */
 
 #include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

vector<vector<int>> dp;
vector<int> arr;
int N;

int isPalindrome(int S, int E) {
	int& ret = dp[S][E];
	if (ret != -1) return ret;
	if (S == E) return ret = 1;
	int s = arr[S];
	int e = arr[E];
	if (S == E - 1) return ret = (s == e);

	if (s != e) ret = 0;
	else ret = isPalindrome(S + 1, E - 1);
	return ret;
}

int main() {

	cin >> N;
	arr = vector<int>(N);
	
	for (int i = 0; i < N; i++) cin >> arr[i];
	dp = vector<vector<int>>(N, vector<int>(N, -1));

	int M;
	cin >> M;
	while (M--) {
		int S, E;
		scanf("%d %d", &S, &E);
		printf("%d\n", isPalindrome(S-1, E-1));
	}

	return 0;
}
