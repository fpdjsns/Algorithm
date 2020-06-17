/**
 * problem : https://leetcode.com/problems/surrounded-regions/
 * algorithm : dfs
 * time complexity : O(NM)
 */

class Solution {
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& check, int x, int y, bool isSet){
        if(board[x][y] == 'X') return;
        int dx[] = { -1, 1, 0, 0 };
        int dy[] = { 0, 0, -1, 1 };
        queue<pair<int, int>> q;
        q.push({x, y});
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if(check[x][y]) continue;
            check[x][y] = true;
            if(isSet) 
                board[x][y] = 'X';
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= board.size()) continue;
                if(ny < 0 || ny >= board[nx].size()) continue;
                if(check[nx][ny]) continue;
                if(board[nx][ny] == 'X') continue;
                q.push({nx,ny});
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(); 
        if(n==0) return;
        int m = board[0].size();
        vector<vector<bool>> check(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            dfs(board, check, i, 0, false);
            dfs(board, check, i, m-1, false);
        }
        for(int i=0;i<m;i++){
            dfs(board, check, 0, i, false);
            dfs(board, check, n-1, i, false);
        }
        
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                dfs(board,check,i,j,true);
            }
        }
    }
};
