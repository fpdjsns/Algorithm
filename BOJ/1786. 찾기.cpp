/**
 * problem : https://www.acmicpc.net/problem/1786
 * algorithm : KMP
 * time complexity : O(N + M)  N=|T|, M=|P|
 */

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <string.h>

using namespace std;

// make pi array 
vector<int> makePi(string str) {
	vector<int> pi(str.size(), 0);
	int sameInd = 0;
	for (int i = 1; i < str.size(); i++) {
		// find sameInd
		while (sameInd > 0 && str[i] != str[sameInd])
			sameInd = pi[sameInd - 1];

		// if find same char
		if (str[sameInd] == str[i]) {
			pi[i] = sameInd + 1;
			sameInd++;
		}
	}
	return pi;
}

vector<int> KMP(string str, string pattern) {
	vector<int> pi = makePi(pattern);

	int strInd = 0;
	int patternInd = 0;
	vector<int> ans;

	while (strInd < str.size()) {
		// check character pattern, str
		if (pattern[patternInd] == str[strInd]) { // find same char
			patternInd++;
			strInd++;
		}
		else if (patternInd > 0) { // different char -> find same prefix
			patternInd = pi[patternInd - 1];
		}
		else  // cannot found same string. => Search again from the first letter of A
			strInd++;

		// find pattern
		if (patternInd == pattern.size()) {
			ans.push_back(strInd - pattern.size() + 1);
			patternInd = pi[patternInd-1];
		}
	}

	return ans;
}


int main() {

	string T, P;
	getline(cin, T);
	getline(cin, P);
	vector<int> ans = KMP(T, P);

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}
