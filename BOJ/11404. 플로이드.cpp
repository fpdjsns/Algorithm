/**
 * problem : https://www.acmicpc.net/problem/11404
 * time complexity : O(N^3)
 * algorithm : Floyd warshall
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> dist(n, vector<int>(n, 1e9));
	int u, v, w;
	for (int i = 0; i<m; i++) {
		cin >> u >> v >> w;
		u--; v--;
		dist[u][v] = min(dist[u][v], w);
	}
	for (int i = 0; i < n; i++) dist[i][i] = 0;

	for (int k = 0; k<n; k++) {
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			if (dist[i][j] == 1e9) cout << "0 ";
			else cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
