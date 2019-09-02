
/*
 * codeground - Practice - 연습문제 - 8. 블럭 없애기
 * 문제 : https://www.codeground.org/practice/practiceProblemList
 * 시간복잡도 : O(N)
 * 알고리즘 : DP
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define inf 1e9
using namespace std;

int solve()
{
	int n;
	cin >> n;
	vector<int> arr(n + 2, 0);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	vector<int> d(n + 2, inf);//d[i] = i번째가 없어질 때까지 걸리는 시간
	d[0] = d[n + 1] = 0;

	//없어질 때까지 걸리는 시간은 양쪽의 영향을 받지만 한 번에 이를 탐색하긴 어려우므로
	//왼쪽과 자신, 자신과 오른쪽을 탐색 두 번으로 각각 구해서 d배열을 채운다.

	for (int i = 1; i <= n; i++)//(왼쪽, 자신) 비교
		d[i] = min(d[i - 1] + 1, arr[i]);//d[i] = min(왼쪽이 없어지는데 걸리는 시간 + 1, 높이가 없어지는데 걸리는 시간)
	for (int i = n; i >= 1; i--)  //(자신, 오른쪽) 비교
		d[i] = min(d[i], min(d[i + 1] + 1, arr[i]));
	
	int ans = 0; //d배열의 최대값
	for (int i = 1; i <= n; i++)
		ans = max(ans, d[i]);
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
