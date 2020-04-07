/**
 * problem : https://www.acmicpc.net/problem/1701
 * algorithm : KMP
 * time complexity : O(N^2)
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
		while (ind > 0 && str[ind] != str[i])
			ind = pi[ind - 1];
		if (str[ind] == str[i])
			pi[i] = ++ind;
	}
	return pi;
}

int solve(string str) {
	int ans = 0;
	for (int start = 0; start < str.size(); start++) {
		vector<int> pi = makePi(str.c_str() + start);
		for (int i = 0; i < pi.size(); i++) {
			ans = max(ans, pi[i]);
		}
	}
	return ans;
}

int main() {
	
	string str;
	cin >> str;
	cout << solve(str) << endl;
	return 0;
}
