/**
 * problem : https://www.acmicpc.net/problem/2143
 * algorithm : two pointer
 * time complexity : O(NlogN)
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, T;
	cin >> T;

	cin >> n;
	vector<int> sumA(n);//A배열의 0~i까지의 합 저장
	cin >> sumA[0];
	for (int i = 1; i < n; i++)
	{
		cin >> sumA[i];
		sumA[i] += sumA[i - 1];
	}

	vector<int> subA;//만들 수 있는 A의 부 배열들의 각 원소의 합
	for (int i = 1; i <= n; i++)
	{
		subA.push_back(sumA[i - 1]);
		for (int j = i; j<n; j++)
			subA.push_back(sumA[j] - sumA[j - i]); //배열의 i~j 합 = (0~j까지의 합) - (0~i-1까지의 합)
	}

	cin >> n;
	vector<int> sumB(n);//B배열의 0~i까지의 합 저장
	cin >> sumB[0];
	for (int i = 1; i < n; i++)
	{
		cin >> sumB[i];
		sumB[i] += sumB[i - 1];
	}
	vector<int> subB;//만들 수 있는 B의 부 배열들의 각 원소의 합
	for (int i = 1; i <= n; i++)
	{
		subB.push_back(sumB[i - 1]);
		for (int j = i; j<n; j++)
			subB.push_back(sumB[j] - sumB[j - i]);
	}

	//오름차순 정렬
	sort(subA.begin(), subA.end());
	sort(subB.begin(), subB.end());

	int L = 0; //subA를 왼쪽에서(작은 수)부터 탐색
	int R = subB.size() - 1; //subB를 오른쪽에서(큰 수)부터 탐색

	long long int ans = 0; //정답
	int sum = 0; //subA[L] + subB[R]
	long long int cntA = 0;//subA[L]과 같은 수의 개수
	long long int cntB = 0;//subB[R]과 같은 수의 개수

	//L과 R이 범위안에 있는 경우
	while (R >= 0 && L < subA.size())
	{
		sum = subA[L] + subB[R];

		int temp;
		if (sum < T) //sum이 구하려는 값보다 작으면 sum을 크게 만들어야 하므로 L++
		{
			temp = L;
			while (L < subA.size() && subA[L] == subA[temp]) L++;
		}
		else if (sum > T) //sum이 구하려는 값보다 크면 sum을 작게 만들어야 하므로 R--
		{
			temp = R;
			while (R >= 0 && subB[R] == subB[temp]) R--;
		}
		else //sum이 구하려는 수면 
		{
			cntA = 0;
			temp = L;
			//subA에서 subA[L]과 같은 수의 개수 세기
			while (L < subA.size() && subA[L] == subA[temp])
			{
				cntA++;
				L++;
			}

			cntB = 0;
			temp = R;
			//subB에서 subB[L]와 같은 수의 개수 세기
			while (R >= 0 && subB[R] == subB[temp])
			{
				cntB++;
				R--;
			}

			ans += cntA * cntB;//경우의 수 구하는 것이기 때문에 곱하기
		}
	}
	cout << ans;
	
	return 0;
}
