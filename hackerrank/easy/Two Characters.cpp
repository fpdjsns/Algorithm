/*
 * problem : https://www.hackerrank.com/challenges/two-characters/problem
 * time complexity : O(N^3 / 2)
 * data structure : string
 */

#include <string>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

const char INIT_CHAR = '0';

// 문자열 s에서 c1, c2 문자를 제외한 모든 문자를 제거했을 때,
// 정답이 가능한 경우 생성함 문자열의 길이를 가져오기.
int getCnt(string s, char c1, char c2) {
	char before = INIT_CHAR;
	int cnt = 0;

	for (int i = 0; i < s.size(); i++) {
		char now = s[i];

		// 제거되어야 하는 문자인 경우 무시
		if (now != c1 && now != c2) continue;

		// 이전과 같은 문자라면 정답 불가능
		if (now == before) return 0;

		before = now;
		cnt++; // 문자길이 + 1
	}
	return cnt;
}

int solve(int N, string s) {

	// 문자열 s의 문자들
	set<char> charSet;

	for (int i = 0; i < N; i++) {
		charSet.insert(s[i]);
	}

	int ans = 0;

	// 문자들의 집합 (c1, c2)들로 정답이 가능한 경우의 길이를 가져와서 최대 길이를 ans에 저장.
	for (set<char>::iterator c1 = charSet.begin(); c1 != charSet.end(); c1++) {
		for (set<char>::iterator c2 = next(c1); c2 != charSet.end(); c2++) {
			ans = max(ans, getCnt(s, *c1, *c2));
		}
	}

	return ans;
}

int main() {
	int N;
	string s;

	cin >> N >> s;
	cout << solve(N, s) << endl;
	return 0;
}
