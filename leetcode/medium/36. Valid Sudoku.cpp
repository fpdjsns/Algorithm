/**
 * problem : https://leetcode.com/problems/valid-sudoku/
 * algorithm : simulation
 */

class Solution {
    bool check(int& visit, char c){
        if(c < '0' || c > '9') return true;
        int num = c - '0';
        if((visit & (1<<num)) > 0) return false;
        visit |= (1<<num);
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // check row, column
        for(int i=0; i<9; i++){
            int rowVisit = 0;
            int colVisit = 0;
            for(int j=0; j<9; j++){
                if(!check(rowVisit, board[j][i])) return false;
                if(!check(colVisit, board[i][j])) return false;
            }
        }
        
        // check sub-boxes
        for(int r=0; r<9; r+=3) {
            for(int c=0; c<9; c+=3) {
                int visit = 0;
                for(int k=0; k<9; k++){
                    if(!check(visit, board[r + (k/3)][c + (k%3)])) 
                        return false;
                }
            }
        }
        return true;
    }
};
