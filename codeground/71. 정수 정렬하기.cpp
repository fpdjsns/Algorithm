
/*
 * codeground - Practice - 연습문제 - 71. 정수 정렬하기
 * 문제 : https://www.codeground.org/practice/practiceProblemList
 * 시간복잡도 : O(NlogN)
 */
 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long Answer;

long long solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i<n; i++)
		cin >> arr[i];
  
  //정렬
	sort(arr.begin(), arr.end());
	
  long long ans = 0;
	for (int i = 0; i<n; i++)
	{
		if (i % 2 == 0) ans += arr[i];
		else ans -= arr[i];
	}
	return ans;
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = solve();
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
