/**
 * problem : https://leetcode.com/problems/shift-2d-grid/
 * time complexity : O(NM)
 */

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int size = row*col;
        
        vector<vector<int>> answer(row, vector<int>(col));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int tmp = (size + (i*col + j - (k % size))) % size;
                answer[i][j] = grid[tmp/col][tmp%col];
            }
        }
        
        return answer;
    }
};
