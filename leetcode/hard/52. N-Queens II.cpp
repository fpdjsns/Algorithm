/**
 * problem : https://leetcode.com/problems/n-queens-ii/
 * time complexity : O(N!)
 * algorithm : backtracking
 */
 
class Solution {
    int answer;
    int N;
    void solve(int row, vector<bool>& checkCol, vector<vector<bool>>& checkDiagnal) {
        if(row == N) {
            answer++;
            return;
        }
        for(int col=0; col<N; col++){
            if(checkCol[col]) continue;
            if(checkDiagnal[0][row-col+N-1]) continue;
            if(checkDiagnal[1][row+col]) continue;
        
            checkCol[col] = true;
            checkDiagnal[0][row-col+N-1] = true;
            checkDiagnal[1][row+col] = true;
        
            solve(row+1, checkCol, checkDiagnal);
            
            checkCol[col] = false;
            checkDiagnal[0][row-col+N-1] = false;
            checkDiagnal[1][row+col] = false;
        }
    }
public:
    int totalNQueens(int n) {
        answer = 0;
        N = n;
        vector<vector<bool>> checkDiagnal(2, vector<bool>(2*(N-1) + 1));
        vector<bool> checkCol(N);
        solve(0, checkCol, checkDiagnal);
        return answer;
        
    }
};
