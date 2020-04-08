/**
 * problem : https://www.acmicpc.net/problem/11585
 * time complexity : O(N) // 좀 더 정확히 보면 O(3N)
 * algorithm : KMP
 */

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

vector<int> makePi(string str) {
	vector<int> pi(str.size(), 0);
	int ind = 0;
	for (int i = 1; i < str.size(); i++) {
		while (ind > 0 && str[i] != str[ind])
			ind = pi[ind - 1];
		if (str[ind] == str[i]) 
			pi[i] = ++ind;
	}
	return pi;
}

int KMP(string str, string pattern) {
	vector<int> pi = makePi(pattern);

	int pInd = 0;
	int ind = 0;
	int cnt = 0;
	while (ind < str.size()) {
		while (pInd > 0 && pattern[pInd] != str[ind])
			pInd = pi[pInd - 1];

		if (pattern[pInd] == str[ind]) {
			pInd++;
			ind++;
		}
		else if (pInd == 0) { // can't find same string
			ind++;
		}

		if (pattern.size() == pInd) {
			cnt++;
			pInd = pi[pInd-1];
			if (ind == pattern.size()) cnt--;
		}
	}
	return cnt;
}

int main() {
	
	int N; cin >> N;
	string str(N, ' '), pattern(N, ' ');
	for (int i = 0; i < N; i++) cin >> str[i];
	for (int i = 0; i < N; i++) cin >> pattern[i];
	int numerator = KMP(str + str, pattern);
	int tmp = gcd(numerator, N);
	cout << numerator / tmp << "/" << N / tmp << endl;
	return 0;
}
