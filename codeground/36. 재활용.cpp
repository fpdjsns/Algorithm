/*
 * codeground - Practice - SCPC 2회 본선 - 36. 재활용
 * 문제 : https://www.codeground.org/practice/practiceProblemList
 * 시간복잡도 : O(N2M)
 * 알고리즘 : DP
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define inf 1e9

using namespace std;

int n, m;
vector<int> arr;
vector<int> sum;
int d[501][501]; //d[s][k] : s~n 까지의 집이 k개의 수집통에 재활용을 넣는 경우 드는 최소 비용

//d[s][k] 채우기
int go(int s, int k)
{
	//끝
	if (s > n) 
	{
		if (k == 0) return 0;//가능
		else return inf;//불가능
	}
	if (k == 0) return inf; //불가능

	int& ret = d[s][k];
	if (ret != -1) return ret;
	ret = inf;
	
	int mid; //중간집 
	int cost; //드는 비용

	//s~i 까지 집들을 수집통 1개로 채우는 경우
	for (int i = s; i <= n; i++)
	{
		mid = (s + i) / 2;
		cost = (sum[i] - sum[mid]) - (sum[mid] - sum[s - 1]) + ((mid -s+1)-(i-mid))*arr[mid];
		ret = min(ret, go(i + 1, k - 1) + cost);
	}
	return ret;
}

int solve()
{
	cin >> n >> m;
	arr.resize(n + 1);
	sum.resize(n + 1);
	memset(d, -1, sizeof(d));

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr.begin(), arr.end()); //오름차순 정렬
	for (int i = 1; i <= n; i++)
	{
		sum[i] = arr[i] + sum[i - 1];
	}
	return go(1,m);
}

int main(int argc, char** argv)
{
	int T, test_case;
	int Answer;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = solve();
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
