/**
 * problem : https://leetcode.com/problems/search-a-2d-matrix-ii/
 * time complexity : O(N+M)
 * algorithm : greedy
 */
 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); int n = matrix[0].size();
        int x = 0;
        int y = n - 1;
        
        while(x < m && y >= 0) {
            // find
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] < target) x++;
            else y--;
        }
        
        return false;
    }
};
