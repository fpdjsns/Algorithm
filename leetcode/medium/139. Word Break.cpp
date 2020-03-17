/**
 * problem : https://leetcode.com/problems/word-break/
 * algorithm : DP
 * time complexity : O(NM) (N = |s|, M = |wordDict|)
 */

class Solution {
	int isMatch(string s, int ind, string word) {
		if (s.size() - ind + 1 < word.size())
			return 0;
		for (int i = 0; i<word.size(); i++) {
			if (word[i] != s[ind + i])
				return 0;
		}
		return ind + word.size();
	}
	vector<int> dp;
	bool isMatch(string s, int ind, vector<string>& wordDict) {
		if (ind == s.size()) return true;
		int& ret = dp[ind];
		if (ret != -1) return ret;
		ret = 0;
		for (int j = 0; j<wordDict.size(); j++) {
			if (wordDict[j][0] == s[ind]) {
				int nextInd = isMatch(s, ind, wordDict[j]);
				if (nextInd == 0) continue;
				ret |= isMatch(s, nextInd, wordDict);
			}
		}
		return ret;
	}
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		dp = vector<int>(s.size(), -1);
		return isMatch(s, 0, wordDict);
	}
};
