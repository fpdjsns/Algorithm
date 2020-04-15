/**
 * problem : https://www.algospot.com/judge/problem/read/GALLERY
 * algorithm : DFS
 * time complexity : O(V + E). V = G, E = H
 */

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string.h>
#define UNWATCHED 0 // 감시중이지 않은 갤러리
#define WATCHED 1 // 감시중인 갤러리
#define INSTALLED 2 // 감시카메라가 설치된 갤러리

using namespace std;

int ans;
vector<bool> check;

int dfs(int now, const vector<vector<int>>& adj) {
	check[now] = true;

	// set children
	vector<int> children = { 0, 0, 0 };
	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		if (check[next]) continue;
		children[dfs(next, adj)]++;
	}

	// 자식들 중 감시중이지 않은 갤러리가 있는 경우
	if (children[UNWATCHED] > 0) {
		ans++; // install
		return INSTALLED;
	}

	// 자식들 중 카메라가 설치되어 있는 갤러리가 있는 경우
	if (children[INSTALLED] > 0) {
		return WATCHED;
	}

	// 리프노드인 경우 카메라 설치를 하면 안되므로
	// 감시 카메라 설치 필요여부는 부모노드로 위임한다.
	return UNWATCHED;
}

int solve(int G, const vector<vector<int>>& adj) {
	// init
	check = vector<bool>(G, false);
	ans = 0;
  
	// 모든 컴포넌트 확인
	for (int i = 0; i < G; i++) {
		if (check[i]) continue;
		if (dfs(i, adj) == UNWATCHED)
			ans++;
	}
	return ans;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int G, H;
		cin >> G >> H;
		vector<vector<int>> adj(G);
		for (int i = 0; i < H; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout << solve(G, adj) << endl;
	}
	return 0;
}
