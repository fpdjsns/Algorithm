/**
 * problem : https://www.hackerrank.com/contests/hourrank-23/challenges/largest-pyramid/problem
 * time complexity : O(max(N,M) * NM)
 * algorithm : DP
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int n, m, k;
int max_down[400][351][351] = { 0 }; //max_down[size][i][j] : j열의 arr[i][j] 부터 arr[i+size-1][j] 중 최대 값
int max_right[400][351][351] = { 0 }; //max_right[size][i][j] : i행의 arr[i][j] 부터 arr[i][j+size-1] 중 최대 값
int arr[351][351]; //arr[i][j] : (i,j) 요소 값
int sum[351][351] = { 0 };; //sum[i][j] : (1,1) ~ (i,j) 까지의 직사각형에 속하는 배열 요소들의 합
int pyramid[400] = { 0 }; //pyramid[i] : 피라미드 크기가 i일 때 피라미드의 합

int solve()
{
	//input
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
			max_down[1][i][j] = max_right[1][i][j] = arr[i][j];
		}
	}

	//피라미드 크기가 size 일 때 (i,j)를 왼쪽 위로 했을 때 max_down[i][j], max_right[i][j] 갱신 
	for (int size = 2; size <= max(n, m); size++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				max_right[size][i][j] = max(max_right[size - 1][i][j], arr[i][j + size - 1]);
				max_down[size][i][j] = max(max_down[size - 1][i][j], arr[i + size - 1][j]);
			}
		}
	}

	//sum 배열 갱신
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];

	//정답 구하기
	int answer = 0;

	//(cx,cy)를 중심으로 만들 수 있는 피라미드 탐색
	for (int cx = 1; cx <= n; cx++)
	{
		for (int cy = 1; cy <= m; cy++)
		{
			//가능한 가장 큰 피라미드 크기
			int posssible_size = min(cx, cy);
			posssible_size = min(posssible_size, min(n - cx + 1, m - cy + 1));
			int current_maxnum = 0;//최근 범위에 포함된 arr배열의 최대 값
			
			//plus : 피라미드 크기 - 1
			for (int plus = 0; plus < posssible_size; plus++)
			{
				//조각을 더해서 (cx, cy)가 중심인 크기가 size인 피라미드 가장자리 arr 최대 값
				int tmp = max_down[2 * plus + 1][cx - plus][cy - plus];
				tmp = max(tmp, max_right[2 * plus + 1][cx - plus][cy - plus]);
				tmp = max(tmp, max_down[2 * plus + 1][cx - plus][cy + plus]);
				tmp = max(tmp, max_right[2 * plus + 1][cx + plus][cy - plus]);

				current_maxnum = max(current_maxnum, tmp + plus);

				//size가 정답보다 같거나 작다면 탐색할 필요 x
				//크기가 size인 피라미드를 만들 수 없으면 탐색할 필요 x
				if (current_maxnum > plus + 1 || plus + 1 < answer) continue;
				
				//now_sum : (cx,cy)를 기준으로 크기가 size인 피라미드에 속한 arr배열들의 합
				//need : 필요한 조각 개수
				int now_sum = sum[cx + plus][cy + plus] - sum[cx - plus -1][cy + plus] - sum[cx + plus][cy - plus - 1] + sum[cx - plus - 1][cy - plus - 1];
				int need = pyramid[plus + 1] - now_sum;
				if (need > k)//만들 수 없음
					break;
				else//만들 수 있음 -> 정답 갱신
					answer = max(answer, plus + 1);
			}
		}
	}
	return answer;
}

int main()
{
	for (int i = 1; i <= 400; i++)
		pyramid[i] = pyramid[i - 1] + (2 * i - 1)*(2 * i - 1);

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int answer = solve();
		cout << answer << endl;
	}
	return 0;
}
