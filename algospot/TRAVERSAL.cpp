/**
 * problem : https://algospot.com/judge/problem/read/TRAVERSAL
 * time complexity : 
 * data structure : tree
 */

#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void solve(vector<int> preArr, vector<int> inArr) {
	int N = preArr.size();
	if (N == 1) cout << preArr[0] << " ";
	if (N <= 1) return;

	int root = preArr[0];
	if (inArr[0] == preArr[0]) {
		vector<int> nextPreArr = vector<int>(N-1);
		vector<int> nextInArr = vector<int>(N-1);
		for (int i = 1; i < N; i++) nextPreArr[i-1] = preArr[i];
		for (int i = 1; i < N; i++) nextInArr[i-1] = inArr[i];
		solve(nextPreArr, nextInArr);
	}
	else {
		int nextN = 0;
		while (nextN < N && inArr[nextN] != root) nextN++;
		vector<int> nextPreArr = vector<int>(nextN);
		vector<int> nextInArr = vector<int>(nextN);
		for (int i = 1; i <= nextN; i++) nextPreArr[i - 1] = preArr[i];
		for (int i = 0; i < nextN; i++) nextInArr[i] = inArr[i];
		solve(nextPreArr, nextInArr);

		nextPreArr = vector<int>(N - nextN - 1);
		nextInArr = vector<int>(N - nextN - 1);
		for (int i = nextN + 1; i < N; i++) {
			nextPreArr[i - nextN - 1] = preArr[i];
			nextInArr[i - nextN - 1] = inArr[i];
		}
		solve(nextPreArr, nextInArr);
	}
	cout << root << " ";
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int N; cin >> N;
		vector<int> preArr(N);
		vector<int> inArr(N);
		for (int i = 0; i < N; i++) cin >> preArr[i];
		for (int i = 0; i < N; i++) cin >> inArr[i];
		solve(preArr, inArr);
		cout << endl;
	}
	return 0;
}
