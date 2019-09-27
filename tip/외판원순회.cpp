/*
 * 외판원 순회(2098): https://www.acmicpc.net/problem/2098
 */
 
#include<iostream>
#define MAX 17000000
#define CITY 16

using namespace std;

int n;
int arr[CITY][CITY];
int d[1 << CITY][CITY] = { 0 };

//visit : 이미 방문한 도시 체크
//now : 이번에 지날 도시 번호
int TSP(int visit, int now)
{
	//now번 도시 방문 추가
	visit |= (1 << now);
	
	//모든 도시를 지난 경우
	if (visit == (1 << n) - 1)
	{
		//now -> 0(출발도시)로 가는 경로 있어야 돌아갈 수 있음
		if (arr[now][0] > 0)
		{
			return arr[now][0];//여행비용 반환
		}
		return MAX;//불가능한 경우 MAX 반환
	}

	int& ret = d[visit][now];
	//memorization
	if (ret > 0)
		return ret;
	ret = MAX;
	for (int i = 0; i < n; i++)
	{
		//now -> 아직 방문하지 않은 i번 도시 가는 경로가 있는 경우 
		if (i != now && (visit&(1<<i))==0 && arr[now][i] > 0)
		{
			//최소 비용 갱신
			int temp = TSP(visit, i) + arr[now][i];
			if (ret > temp)
				ret = temp;
		}
	}
	return ret;
}

int main()
{
	int ans;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	ans = TSP(0, 0);
	if (ans == MAX) printf("-1\n");
	else printf("%d\n", ans);

	return 0;
}
