/**
 * problem: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
 * time complexity: O(NlogN)
 */
 
class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		vector<pair<int, int>> arr(mat.size());
		for (int i = 0; i<mat.size(); i++) {
			int ind = 0;
			while (ind < mat[i].size() && mat[i][ind] == 1) ind++;
			arr[i] = { ind, i };
		}
		sort(arr.begin(), arr.end());

		vector<int> ans(k);
		for (int i = 0; i<k; i++) ans[i] = arr[i].second;
		return ans;
	}
};
