/**
 * problem : https://leetcode.com/problems/combination-sum-iii/
 * algorithm : backtracking
 * time complexity : O(2^9)
 */
 
class Solution {

	vector<vector<int>> answer;
	void backTracking(int before, int k, int n, vector<int>& combi, int check) {
		if (k < 0 || n < 0) return;
		if (n == 0 && k == 0) answer.push_back(combi);
		if (9 * k < n) return;

		for (int i = before + 1; i <= 9; i++) {
			combi.push_back(i);
			backTracking(i, k - 1, n - i, combi, check | 1 << i);
			combi.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum3(int k, int n) {
		answer = vector<vector<int>>();
		vector<int> tmp;
		backTracking(0, k, n, tmp, 0);
		return answer;
	}
};
