/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/1844
 * algorithm : BFS
 * time complexity : O(NM)
 */
 
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
	int answer = -1;
	int n = maps.size();
	int m = maps[0].size();
	vector<vector<bool>> check(n, vector<bool>(m));
	queue<pair<pair<int, int>,int>> q;
	q.push({ {0,0},1 });//시작 위치
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (x == n - 1 && y == m - 1)
		{
			answer = cnt;
			break;
		}
		if (check[x][y]) continue;
		check[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (check[nx][ny] || maps[nx][ny] == 0) continue;
			q.push({{ nx,ny }, cnt + 1});
		}
	}
	return answer;
}
