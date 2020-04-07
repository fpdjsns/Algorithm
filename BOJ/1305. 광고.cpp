/**
 * problem : https://www.acmicpc.net/problem/1305
 * algorithm : KMP
 * time complexity : O(L)
 */
 
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

vector<int> makePi(string str) {
	vector<int> pi(str.size(), 0);
	int sameInd = 0;
	for (int i = 1; i < str.size(); i++) {
		// find sameInd
		while (sameInd > 0 && str[sameInd] != str[i]) {
			sameInd = pi[sameInd - 1];
		}

		if (str[sameInd] == str[i]) {
			pi[i] = ++sameInd;
		}
	}
	return pi;
}

int solve(int L, string str) {
	vector<int> pi = makePi(str);
	return L - pi[str.size() - 1];
}

int main() {

	int L;
	cin >> L;
	string str;
	cin >> str;
	cout << solve(L, str);

	return 0;
}
