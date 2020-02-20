/**
 * problem : https://leetcode.com/problems/print-words-vertically/
 * time complexity : O(N)
 */

#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
class Solution {
public:
	vector<string> printVertically(string s) {
		vector<string> ans;
		int wordCnt = 0;
		int ind = 0;
		for (int i = 0; i < s.size(); i++) {
			char now = s[i];
			if (now == ' ') {
				ind = 0;
				wordCnt++;
				continue;
			}
			if (ans.size() <= ind) {
				ans.resize(ind + 1);
				for (int j = 0; j < wordCnt; j++) ans[ind] += ' ';
			}
			for (int j = ans[ind].size(); j < wordCnt; j++) ans[ind] += ' ';
			ans[ind++] += now;
		}
		return ans;
	}
};


int main() {
	string s = "TO BE OR NOT TO BE";
	vector<string> ans = Solution().printVertically(s);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
