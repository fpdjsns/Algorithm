/**
 * problem : https://algospot.com/judge/problem/read/BRACKETS2
 * time complexity : O(N)
 * data structure : stack
 */

#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solve(string s) {
	stack<char> st;
	vector<char> opens = { '(', '{', '[' };
	vector<int> closes = { ')', '}', ']' };

	for (int i = 0; i < s.size(); i++) {
		char now = s[i];

		// 열린괄호 체크
		for (int j = 0; j < opens.size(); j++) {
			if (opens[j] != now) continue;
			
			// 스택에 push
			st.push(now);
		}

		// 닫힌괄호 체크
		for (int j = 0; j < closes.size(); j++) {
			if (closes[j] != now) continue;

			// 가장 위에 있는 짝이 없는 열린 괄호와 짝이 맞는지 확인
			if (st.empty() || st.top() != opens[j]) return false;
			st.pop();
		}
	}

	// 열린 괄호가 아직 남은 경우 false
	return st.empty();
}

int main() {

	int C;
	cin >> C;

	while (C--) {
		string s;
		cin >> s;
		if (solve(s)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
