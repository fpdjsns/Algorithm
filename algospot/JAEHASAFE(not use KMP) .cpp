/**
 * problem: https://algospot.com/judge/problem/read/JAEHASAFE
 * time complexity: O(NM) (M = numer of pictures's size)
 * data structure: string
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * s: 시작 문자열 2개를 이어붙인 문자열
 * ind: 문자열 시작 인덱스
 * isClockwise: 시계방향인지
 *
 * s[ind ~ ind + s.size()/2) 문자열을 isClockwise 방향으로 한 칸 움직였을 때의 문자열
 * O(1)
 */
string getMoveNext(string s, int& ind, bool isClockwise) {
	if (isClockwise) ind -= 1;
	else ind += 1;

  // 시작인덱스 범위 = [0, s.size() /2)
	int size = s.size() / 2;
	ind = (ind + size) % size;

	return s.substr(ind, size);
}
 
int solve(string first, vector<string> patterns) {
	int size = first.size();
	
  // 시작 문자열 2개를 이어붙인 문자열
	string doubleFirst = first + first;
	int ind = size;

	int ans = 0;
	string now = first;
	bool isClockwise = true;
	
	for (int i = 0; i < patterns.size(); i++) {
		string pattern = patterns[i];
		int cnt = 0; // 움직인 횟수

		for (int j = 0; j <= size - 1; j++) {
			if (now == pattern) { // 패턴과 같다면
				break;
			}

			now = getMoveNext(doubleFirst, ind, isClockwise);
			cnt++;
		}

		ans += cnt;
		isClockwise = !isClockwise; // 방향 변경
	}

	return ans;
}

int main() {
	int T, N;
	cin >> T;

	string first, tmp;
	while (T--) {
		cin >> N;
		vector<string> pattern = vector<string>(N);

		cin >> first;
		for (int i = 0; i < N; i++) {
			cin >> pattern[i];
		}

		cout << solve(first, pattern) << endl;
	}
	
	return 0;
}
