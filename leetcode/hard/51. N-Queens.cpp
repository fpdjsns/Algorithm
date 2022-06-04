/**
 * problem : https://leetcode.com/problems/n-queens/
 * time complexity : O(N!)
 * algorithm : backtracking
 */
 
class Solution {
    vector<vector<string>> answer;
    int N;
    string DEFAULT;
    void solve(int row, vector<string>& tmp, vector<bool>& checkCol, vector<vector<bool>>& checkDiagnal) {
        if(row == N) {
            answer.push_back(tmp);
            return;
        }
        for(int col=0; col<N; col++){
            if(checkCol[col]) continue;
            if(checkDiagnal[0][row-col+N-1]) continue;
            if(checkDiagnal[1][row+col]) continue;
            checkCol[col] = true;
            checkDiagnal[0][row-col+N-1] = true;
            checkDiagnal[1][row+col] = true;
            
            string str = DEFAULT;
            str[col] = 'Q';
            tmp[row] = str;
            solve(row+1, tmp, checkCol, checkDiagnal);
            
            checkCol[col] = false;
            checkDiagnal[0][row-col+N-1] = false;
            checkDiagnal[1][row+col] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        answer = vector<vector<string>>();
        N = n;
        DEFAULT = string(N, '.');
        vector<string> tmp(N);
        vector<vector<bool>> checkDiagnal(2, vector<bool>(2*(N-1) + 1));
        vector<bool> checkCol(N);
        solve(0, tmp, checkCol, checkDiagnal);
        return answer;
    }
};
