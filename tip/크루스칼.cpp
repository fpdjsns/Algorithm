/**
 * 네트워크 연결(1922) : https://www.acmicpc.net/problem/1922. MST. 유니온파인드 이용해서 크루스칼 알고리즘 구현
 */
 
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> p;

typedef struct Edge
{
	int a, b, w;
}dot;

bool compare(const Edge& a, const Edge& b)
{
	return a.w < b.w;
}

int Find(int n)
{
	if (p[n] == -1) return n;
	p[n] = Find(p[n]);
	return p[n];
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a == b)//같은 그룹이라면
		return false;
	p[b] = a;
	return true;
}

int main()
{
	int n, m;
	int a, b, w;
	cin >> n >> m;

	vector<Edge> E(m);
	p.resize(n, -1);
	int cnt = 0;
	int ans = 0;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> w;
		E[i].a = --a;
		E[i].b = --b;
		E[i].w = w;
	}

	Edge now;
	sort(E.begin(), E.end(), compare);//가중치 기준 내림차순 정렬
	for (int i = 0; i < m; i++)
	{
		now = E[i];
		if (Union(now.a, now.b))//합칠 수 있으면
		{
			ans += now.w;
			cnt++;
			if (cnt == n - 1)
				break;
		}
	}

	if (cnt == n - 1)//모든 컴퓨터 연결 가능
		cout << ans;

	return 0;
}
