/**
 * problem : https://algospot.com/judge/problem/read/TIMETRIP
 * algorithm : Prim
 * time complexity : O(VE)
 */
#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

#define START 0
#define END 1

using namespace std;

int INF = 1e9;
string UNREACHABLE = "UNREACHABLE";
string INFINITY_PATH = "INFINITY";

pair<bool, int> solve(vector<vector<pair<int, int>>> adj) {
	int V = adj.size();

	//dist[i] : 1번에서 i로 가는 최단거리
	vector<int> dist(V, INF);
	dist[START] = 0;

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[j] == INF) continue;
			for (auto next : adj[j])
				dist[next.first] = min(dist[next.first], dist[j] + next.second);
		}
	}

	bool ok = true;
	//한번 더(n번째) 돌렸는데
	for (int i = 0; i < V; i++) {
		for (auto next : adj[i])
			//갱신 되는 값이 있음
			if (dist[next.first] > dist[i] + next.second) {
				ok = false;//음수 사이클 존재
				break;
			}
	}

	if (dist[END] == INF)
		return { false, INF };

	if (!ok)
		return { true, INF };

	return { true, dist[END] };
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int V, W;
		cin >> V >> W;

		vector<vector<pair<int, int>>> minAdj(V);
		vector<vector<pair<int, int>>> maxAdj(V);

		int a, b, c;
		for (int i = 0; i < W; i++) {
			cin >> a >> b >> c;
			minAdj[a].push_back({ b, c });
			maxAdj[a].push_back({ b, -c });
		}

		pair<bool, int> minAns = solve(minAdj);
		if (!minAns.first) {
			cout << UNREACHABLE << endl;
			continue;
		}
		pair<bool, int> maxAns = solve(maxAdj);
		
		cout << (minAns.second == INF ? INFINITY_PATH : to_string(minAns.second));
		cout << " ";
		cout << (maxAns.second == INF ? INFINITY_PATH : to_string(maxAns.second == 0 ? 0 : -maxAns.second)) << endl;
	}
	return 0;
}
