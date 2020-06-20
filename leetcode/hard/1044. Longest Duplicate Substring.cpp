/**
 * problem : 
 * algorithm : binary search, Rabin-Karp
 * time complexity : O(NlogN)
 */

class Solution {
	string getAns(string& s, int length) {
		unordered_map<int, vector<int>> dictionary;
		int MOD = 1e9 + 7;
		int mul = 26;
		long power = 1;
		for (int i = 1; i < length; i++) {
			power = (power * mul) % MOD;
		}
		long hash = 0;

		for (int i = 0; i < length; i++) {
			hash = (mul * hash + s[i] - 'a') % MOD;
		}
		dictionary[hash].push_back(0);
		for (int i = length; i < s.size(); i++) {
			hash = ((hash - power * (s[i - length] - 'a')) % MOD + MOD) % MOD;
			hash = (hash * mul + (s[i] - 'a')) % MOD;

			// check really ans
			if (dictionary[hash].size() != 0) {
				string word = s.substr(i - length + 1, length);
				vector<int> startInds = dictionary[hash];
				for (int j = 0; j<startInds.size(); j++) {
					if (word == s.substr(startInds[j], length))
						return word;
				}
			}
			dictionary[hash].push_back(i - length + 1);
		}
		return "";
	}
public:
	string longestDupSubstring(string S) {
		int l = 0;
		int r = S.size() - 1;
		string ans;
		while (l <= r) {
			int m = (l + r) / 2;
			string tmp = getAns(S, m);
			if (tmp.size() == 0) // impossible
				r = m - 1;
			else { // possible
				ans = tmp;
				l = m + 1;
			}
		}
		return ans;
	}
};
