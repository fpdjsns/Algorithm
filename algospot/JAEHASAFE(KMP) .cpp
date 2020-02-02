/**
* problem: https://algospot.com/judge/problem/read/JAEHASAFE
* time complexity: O(N + M) (M = numer of pictures's size)
* data structure: string
* algorithm : KMP
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// O(|s| + |pattern|)
// s 문자열에서 pattern 문자열이 있는 시작 인덱스 가져오기
int KMP(string s, string pattern) {

	int patternSize = pattern.size();

	// make pi array
	vector<int> pi = vector<int>(patternSize, 0);
	int sameInd = 0;
	for (int i = 1; i < patternSize; i++) {
		while (sameInd > 0 && pattern[i] != pattern[sameInd])
			sameInd = pi[sameInd - 1];
		if (pattern[sameInd] == pattern[i]){
			pi[i] = sameInd + 1;
			sameInd++;
		}
	}

	// Get start index where P from S
	int sInd = 0;
	int patternInd = 0;
	while (sInd < s.size()) {
		if (pattern[patternInd] == s[sInd]) {
			patternInd++;
			sInd++;
		}
		else if (patternInd > 0) {
			patternInd = pi[patternInd - 1];
		}
		else {
			sInd++;
		}

		// find pattern
		if (patternInd == patternSize)
			return sInd - patternSize;
	}

	return -1; // Not found pattern from s
}

int solve(vector<string> patterns) {
	// 시작 문자열 2개를 이어붙인 문자열
	int ans = 0;
	bool isClockwise = true;

	for (int i = 1; i < patterns.size(); i++) {
		if (isClockwise) // 시계방향
			ans += KMP(patterns[i] + patterns[i], patterns[i - 1]);
		else
			ans += KMP(patterns[i - 1] + patterns[i - 1], patterns[i]);
		isClockwise = !isClockwise; // 방향 변경
	}

	return ans;
}

int main() {
	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		vector<string> patterns = vector<string>(N + 1);
		for (int i = 0; i <= N; i++) {
			cin >> patterns[i];
		}

		cout << solve(patterns) << endl;
	}

	return 0;
}
