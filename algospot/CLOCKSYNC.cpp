/*
 * 문제 : https://algospot.com/judge/problem/read/CLOCKSYNC
 * 시간복잡도 : O(4^N) // N : switch 갯수
 * 알고리즘 : 완전탐색
 */

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include<iostream>

#define MAX 1e9
#define SIZE 16

using namespace std;

vector<vector<int>> switches = {
	{ 0, 1, 2 }, // 0
	{ 3, 7, 9, 11 }, // 1
	{ 4, 10, 14, 15 }, // 2
	{ 0, 4, 5, 6, 7 }, // 3
	{ 6, 7, 8, 10, 12 }, // 4 
	{ 0, 2, 14, 15 }, // 5
	{ 3, 14, 15 }, // 6
	{ 4, 5, 7, 14, 15 }, // 7
	{ 1, 2, 3, 4, 5 }, // 8
	{ 3, 4, 5, 9, 13 } // 9
};

int ans = MAX;

void solve(vector<int> arr, int switchInd, int cnt) {

	bool canAns = true;
	for (int i = 0; i < SIZE; i++) {
		canAns &= (arr[i] == 12);
	}

	if (canAns) { 
		ans = min(ans, cnt);
		return;
	}

	if (switchInd == 10) return;

	// if exceed 4 time -> same state
	for (int i = 0; i < 4; i++) {
		solve(arr, switchInd + 1, cnt + i);
		for (int j = 0; j < switches[switchInd].size(); j++) {
			int now = switches[switchInd][j];
			arr[now] += 3;
			if (arr[now] > 12) arr[now] -= 12;
		}
	}
}

int main() {
	int C;
	cin >> C;

	while (C--) {
		vector<int> arr(SIZE);
		for (int i = 0; i < SIZE; i++) {
			cin >> arr[i];
		}
		ans = MAX;
		solve(arr, 0, 0);
		if (ans == MAX) ans = -1;
		cout << ans << endl;
	}
	return 0;
}
