/*
 * codeground - Practice - SCPC 5회 예선 - 98. 소수 수열
 * 문제 : https://www.codeground.org/practice/practiceProblemList
 * 시간복잡도 : O(NlogN)
 * 알고리즘 : DP
 */
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;
const int MAX = 30000;

vector<bool> isPrime(MAX + 1, true);
vector<int> maxScore(MAX + 1, -1);

int getScore(int num) {

	int& ret = maxScore[num];
	if (ret != -1) return ret;

	if (!isPrime[num])
		return ret = 0; // impossible

	if (num / 10 == 0) // 일의 자리
		return ret = 1;

	for (int digit = 1; num % digit != num; digit *= 10) {
		int tmp = num / (digit * 10);
		tmp *= digit;
		tmp += num % digit;
		ret = max(ret, getScore(tmp));
	}

	return ret += 1;
}

int main(int argc, char** argv)
{
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= MAX; i++)
		for (int j = i + i; j <= MAX; j += i)
			isPrime[j] = false;

	int T, test_case;
	int A, B;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> A >> B;

		int aScore = getScore(A);
		int bScore = getScore(B);

		if (aScore > bScore) Answer = 1;
		else if (aScore < bScore) Answer = 2;
		else Answer = 3;

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
