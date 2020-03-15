/**
 * problem : https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
 * time complexity : O(N^2 * M) (N = |arr|, M = |arr[i]|)
 * algorithm : dfs, backtracking
 */

class Solution {
private: 
	int ans = 0;
	void dfs(int ind, vector<string>& arr, set<int>& exist) {
		ans = max(ans, (int)exist.size());

		for (int i = ind; i < arr.size(); i++) {
			string next = arr[i];
			set<int> nextExist = exist;
			for (int i = 0; i < next.size(); i++) 
				nextExist.insert(next[i] - 'a');		
			if (nextExist.size() < exist.size() + next.size()) continue;
			dfs(i + 1, arr, nextExist);
		}
		
	}
public:
	int maxLength(vector<string>& arr) {
		set<int> exist = set<int>();
		dfs(0, arr, exist);
		return ans;
	}
};
