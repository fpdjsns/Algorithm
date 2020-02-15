/**
 * problem: https://leetcode.com/problems/sort-the-matrix-diagonally/
 * time complexity: O(N^2 logN)
 * data structure: heap
 */
 
class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		int m = mat.size();
		int n = mat[0].size();
		vector<priority_queue<int>> heapArr(m + n - 1);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				heapArr[j - i + m - 1].push(-mat[i][j]);
            }
		}

		for (int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++){
				mat[i][j] = -heapArr[j - i + m - 1].top();
				heapArr[j - i + m - 1].pop();
			}
		}
		return mat;
	}
};
