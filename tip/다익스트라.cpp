/*
 * 최소비용 구하기 (1916) : https://www.acmicpc.net/problem/1916 다익스트라 최단경로
 */
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
#define MAX 100000000
using namespace std;

int main()
{
	int n, m;
	int u, v, w;
	int s, e;
	cin >> n >> m;
	vector<vector<int>> arr(n + 1, vector<int> (n+1, MAX)); //arr[i]
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		arr[u][v] = min(arr[u][v], w);
	}
	cin >> s >> e;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	vector<bool> check(n + 1, false);//지났는지 체크
	vector<int> dist(n + 1, MAX);//시작도시에서 ind 도시로 가는 최소 비용

	q.push(make_pair(0,s));
	dist[s] = 0;
	
	int now, weight;
	while (!q.empty())
	{
		now = q.top().second;
		q.pop();
		if (check[now])
			continue;
		check[now] = true;
		for (int next = 1; next <= n; next++)
		{
			weight = arr[now][next];
			if (check[next]) continue; //이미 최단거리 구한 도시라면
			if (weight == MAX) continue; //길이 없다면
			if (dist[next] > dist[now] + weight) //최단거리 찾았으면
			{
				dist[next] = dist[now] + weight;
				q.push(make_pair(dist[next], next));
			}
		}
	}
	cout << dist[e];
	return 0;
}
