/** 
 * problem : https://leetcode.com/problems/set-matrix-zeroes/
 * time complexity : O(NM)
 */
 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size();
        
        set<int> rows;
        set<int> cols;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] != 0) continue;
                rows.insert(i);
                cols.insert(j);
            }
        }
        
        for(auto row: rows) 
            for(int i=0; i<m; i++)
                matrix[row][i] = 0;
        for(auto col: cols) 
            for(int i=0; i<n; i++)
                matrix[i][col] = 0;
    }
};
