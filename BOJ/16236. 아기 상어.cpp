/**
 * problem : https://www.acmicpc.net/problem/16236
 * time complexity : O(N*N * log(N*N))
 * algorithm : BFS
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#define SHARK_LOC 9

using namespace std;

int N;
int answer = 0;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void bfs(int x, int y, int cnt, vector<vector<int>>& arr) {

}

int main() {
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(N));
	pair<int, int> loc = { 0,0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == SHARK_LOC) {
				loc = { i , j }; arr[i][j] = 0;
			}
		}
	}
	answer = 0;
	int sharkSize = 2;
	const int MAX_DIST = N * N;
	int eatedFishes = 0; // 상어 크기가 커진 이후 먹은 물고기 수

	while (1) {
		priority_queue<pair<int, pair<int, int>>, 
			vector<pair<int, pair<int, int>>>,
			greater<pair<int, pair<int, int>>>> q;
		vector<vector<bool>> visits(N, vector<bool>(N, false));

		q.push({ 0, loc });
		visits[loc.first][loc.second] = true;
		int minDist = MAX_DIST;
		while (!q.empty()) {
			int x = q.top().second.first;
			int y = q.top().second.second;
			int dist = q.top().first;
			q.pop();

			if (minDist < dist) break;
			if (arr[x][y] > 0 && arr[x][y] < sharkSize) {
				minDist = dist;
				loc = { x, y };
				break;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // check arr boundary
				if (visits[nx][ny]) continue;
				visits[nx][ny] = true;
				if (arr[nx][ny] > sharkSize) continue; // check shark size
				q.push({ dist + 1, { nx,ny } });
			}
		}
		if (minDist == MAX_DIST) break;
		eatedFishes++;
		// update shark size
		arr[loc.first][loc.second] = 0;
		if (eatedFishes >= sharkSize) { eatedFishes -= sharkSize; sharkSize++; }
		answer += minDist;
	}

	cout << answer << endl;

	return 0;
}
