/**
 * problem : https://leetcode.com/problems/game-of-life/
 * time complexity : O(NM)
 */
 class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(); int n = board[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 0) continue;
                for(int k=0; k<8; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    ans[nx][ny]++;
                }
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 1) board[i][j] = (ans[i][j] == 2 || ans[i][j] == 3);
                else board[i][j] = ans[i][j] == 3;
            }
        }
    }
};
