/*
 * 네트워크 연결 (1922) : https://www.acmicpc.net/problem/1922 프림 MST 최소신장트리
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> arr(n + 1);
	vector<bool> check(n + 1, false);
	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		arr[u].push_back(make_pair(v, w));
		arr[v].push_back(make_pair(u, w));
	}

	priority_queue<pair<int,int>> q;//(w,v)
	for (int i = 0; i < arr[1].size(); i++)
		q.push(make_pair(-arr[1][i].second,arr[1][i].first));
	check[1] = true;
	pair<int,int> now, next;
	int ans = 0;
	while (!q.empty())
	{
		now = q.top();
		q.pop();
		if (check[now.second])
			continue;
		check[now.second] = true;
		ans -= now.first;

		for (int i = 0; i < arr[now.second].size(); i++)
		{
			next = arr[now.second][i];
			if (!check[next.first])
				q.push(make_pair(-next.second, next.first));
		}
	}
	cout << ans;
	return 0;
}
