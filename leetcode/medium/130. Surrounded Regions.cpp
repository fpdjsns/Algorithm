/**
 * problem : https://leetcode.com/problems/surrounded-regions/
 * algorithm : dfs
 * time complexity : O(NM)
 */

class Solution {
    int n, m;
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& check, int x, int y, bool setToX) {
        if(board[x][y] == 'X') return;
        if(check[x][y]) return; 
        
        queue<pair<int,int>> q;
        q.push({x,y});
        check[x][y] = true;
        while(!q.empty()) {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            if(setToX) board[x][y] = 'X';
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(check[nx][ny]) continue;
                if(board[nx][ny] == 'X') continue;
                
                check[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        
        vector<vector<bool>> check(m, vector<bool>(n, false));
        
        // 테두리에서부터 시작하는 'O'는 탐색 처리를 다 한다.
        for(int i=0; i<m; i++){
            dfs(board,check,i,0,false);
            dfs(board,check,i,n-1,false);
        }
        for(int j=0; j<n; j++){
            dfs(board,check,0,j,false);
            dfs(board,check,m-1,j,false);
        }
        
        // 탐색하면서 O -> X
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dfs(board,check,i,j,true);
            }
        }
    }
};
