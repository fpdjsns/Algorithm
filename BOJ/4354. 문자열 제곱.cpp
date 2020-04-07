/**
 * problem : https://www.acmicpc.net/problem/4354
 * algorithm : KMP
 * time complexity : O(N)  // N=|str|
 */

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

vector<int> makePi(string str) {
	vector<int> pi(str.size(), 0);
	int ind = 0;
	for (int i = 1; i < str.size(); i++) {
		while (ind > 0 && str[ind] != str[i]) {
			ind = pi[ind - 1];
		}

		if (str[ind] == str[i]) {
			pi[i] = ++ind;
		}
	}	
	return pi;
}

int solve(string str) {
	vector<int> pi = makePi(str);
	int size = str.size();
	int patternSize = pi.size() - pi[size - 1];

	if (size / 2 < patternSize || size % patternSize != 0) return 1;
	return size / patternSize;
}

int main() {
	
	string str;
	cin >> str;
	while (str != ".") {
		cout << solve(str) << endl;
		cin >> str;
	}
	
	return 0;
}
