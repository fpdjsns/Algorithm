/**
 * problem : https://www.acmicpc.net/problem/1199
 * time complexity : O(V + E)
 * algorithm : Euler circuit, dfs
 */

#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


int n;
vector<vector<int>> arr;
vector<int> ans;

int getStart() {
	int ans = -1;
	for (int u = 0; u < n; u++) {
		int degree = 0;
		for (int v = 0; v < n; v++) {
			degree += arr[u][v];
		}
		if (degree % 2 == 1) {
			return -1;
		}
		if (degree > 0 && ans == -1) {
			ans = u;
		}
	}
	return ans;
}

void dfs(int u) {
	for (int v = 0; v < n; v++) {
		if (arr[u][v] <= 0) continue;
		arr[u][v]--;
		arr[v][u]--;
		dfs(v);
	}
	ans.push_back(u + 1);
}

vector<int> EulerianTrail() {
	int start = getStart();
	if (start == -1) {
		ans.push_back(-1);
		return ans;
	}

	dfs(start);
	return ans;
}

int main() {
	cin >> n;
	arr = vector<vector<int>>(n, vector<int>(n));
	for (int u = 0; u < n; u++) {
		for (int v = 0; v < n; v++) {
			cin >> arr[u][v];
		}
	}
	
	EulerianTrail();
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}
