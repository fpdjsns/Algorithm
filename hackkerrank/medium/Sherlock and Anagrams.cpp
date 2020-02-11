/**
 * problem : https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
 * time complexity : O(N^2)
 * data structure : String
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int sherlockAndAnagrams(string s) {
	int N = s.size();
	string startS = "";
	int ans = 0;
	for (int len = 1; len <= N; len++) {
		string prev = startS;
		startS += s.substr(len - 1, 1);
		map<string, int> m;

		for (int j = len - 1; j < N; j++) {
			string now = prev;
			now += s.substr(j, 1);

			prev = now;
			prev.erase(0, 1);

			sort(now.begin(), now.end());
			m[now]++;
		}
		for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
			int cnt = it->second;
			ans += cnt * (cnt - 1) / 2;
		}
	}
	return ans;
}

int main()
{
	int q;
	cin >> q;

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string s;
		cin >> s;

		int result = sherlockAndAnagrams(s);
		cout << result << endl;
	}

	return 0;
}
