
/*
 * codeground - Practice - SCPC 6회 예선 - 123. 다이어트
 * problem : https://www.codeground.org/practice/practiceProblemList
 * time complexity : O(NlogN + K)
 * algorithm : greedy
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		
		int N, K;
		cin >> N >> K;
		vector<int> A(N);
		vector<int> B(N);
		for (int i = 0; i < N; i++) cin >> A[i];
		for (int i = 0; i < N; i++) cin >> B[i];
		sort(A.begin(), A.end());
		sort(B.begin(), B.end(), [](const int& a, const int& b) { return a > b; });
		for (int i = 0; i < K; i++) {
			Answer = max(Answer, A[i] + B[N - K + i]);
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
