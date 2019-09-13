/*
 * codeground - Practice - SCPC 2회 예선 - 31. 프리랜서
 * 문제 : https://www.codeground.org/practice/practiceProblemList
 * 시간복잡도 : O(N)
 */

#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int n;
vector<int> P, Q;
int d[2][10002];

int go(int ind)
{
	if (ind <= 0)
		return 0;
	int& r1 = d[0][ind];//ind 번째 P사 선택
	int& r2 = d[1][ind];//ind 번째 Q사 선택
	if (r1 == -1)
		r1 = go(ind - 1) + P[ind];
	if (r2 == -1)
		r2 = go(ind - 2) + Q[ind];

	return max(r1, r2);
}

int solve()
{
	cin >> n;
	P.clear(); P.resize(n + 1, 0);
	Q.clear(); Q.resize(n + 1, 0);
	memset(d, -1, sizeof(d));

	for (int i = 1; i <= n; i++)
		scanf("%d", &P[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &Q[i]);

	return go(n);
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
