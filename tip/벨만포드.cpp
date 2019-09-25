/*
 * 타임머신 (11657) : https://www.acmicpc.net/problem/11657 벨만포드 최단경로
 * 시간복잡도 : O(VE)
 */
 #include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1e9

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a, b, c;
	vector<vector<pair<int,int>>> adj(n + 1);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}

	vector<int> dist(n + 1, MAX);//dist[i] : 1번에서 i로 가는 최단거리
	dist[1] = 0;//출발지점 최단 거리 = 0
	for (int i = 0; i < n - 1; i++)//n-1번 간선들 탐색
	{
		for (int j = 1; j <= n; j++)//j 정점 탐색
		{
			if (dist[j] == MAX) continue;//j번 정점이 아직 최단거리 갱신이 되지 않음 통과
			for (auto next : adj[j])
				dist[next.first] = min(dist[next.first], dist[j] + next.second);//최단거리 갱신
		}
	}
	bool ok = true;
	//한번 더(n번째) 돌렸는데
	for (int i = 1; i <= n; i++)
	{
		for (auto next : adj[i])
			//갱신 되는 값이 있음
			if (dist[next.first] > dist[i] + next.second)
			{
				ok = false;//음수 사이클 존재
				break;
			}
	}
	if (!ok)//음수 사이클이 존재한다면
		cout << -1;
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (dist[i] == MAX)//갱신되지 않았다면 연결되지 최단거리 없음을 의미
				cout << -1 << endl;
			else
				cout << dist[i] << endl;
		}
	}
	return 0;
}
