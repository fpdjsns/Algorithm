/*
 * codeground - Practice - 연습문제 - 52. 최대 직사각형
 * 문제 : https://www.codeground.org/practice/practiceProblemList
 * 시간복잡도 : O(N3)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve()
{
	int n;
	cin >> n;
	vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0)); 
	int maxnum = -51;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &sum[i][j]);
			maxnum = max(maxnum, sum[i][j]);
			sum[i][j] += sum[i][j - 1];
		}
	}
	if(maxnum<=0)
		return maxnum;

	int ans = -1000000000;
	int tmp, row;
	//(k,j) ~ (k,i) 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			row = 0;
			for (int k = 1; k <= n; k++)
			{
				tmp = sum[k][i] - sum[k][j - 1];
				row = max(tmp, row + tmp);
				ans = max(ans, row);
			}
		}
	}

	return ans;
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
