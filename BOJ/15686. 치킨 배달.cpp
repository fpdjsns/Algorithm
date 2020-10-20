/**
 * problem : https://www.acmicpc.net/problem/15686
 * algorithm : backtracking
 * time complexity : O(|houses|^|chickens|)
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<vector<int>>> dp;
vector<pair<int, int>> houses, chickens;
int answer;
int N, M;

void backtracking(vector<int> dist, int ind, int cnt, int sum) {
	if (ind >= chickens.size()) return;
	if (cnt >= M) return;

	backtracking(dist, ind + 1, cnt, sum);

	pair<int, int> chi = chickens[ind];
	int tmp = 0;
	for (int i = 0; i < dist.size(); i++) {
		int x = abs(houses[i].first - chi.first);
		int y = abs(houses[i].second - chi.second);
		dist[i] = min(x + y, dist[i]);
		tmp += dist[i];
	}
	answer = min(answer, tmp);
	backtracking(dist, ind + 1, cnt + 1, tmp);
}

int main() {
	cin >> N >> M;
	
	int tmp;
	houses = vector<pair<int, int>>();
	chickens = vector<pair<int, int>>();
	answer = 1e9;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp == 1) houses.push_back({ i, j });
			else if (tmp == 2) chickens.push_back({ i,j });
		}
	}
	vector<int> dist(houses.size(), 1e9);
	vector<pair<int, int>> selects;
	backtracking(dist, 0, 0, 0);
	cout << answer << endl;
	return 0;
}
