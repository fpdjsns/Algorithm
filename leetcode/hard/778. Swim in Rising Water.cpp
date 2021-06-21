/**
 * problem : https://leetcode.com/problems/swim-in-rising-water/
 * algorithm : Dijkstra
 * time complexity : O(N^2 log(N^2)) // grid = N x N
 */

class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int,int>>> q; // {elevation , {x, y}}
        q.push({0, {0, 0}});
        int answer = grid[0][0];
        int n = grid.size(); int m = grid[0].size();
        vector<vector<bool>> check(n, vector<bool>(m, false));
        check[0][0] = true;
        while(!q.empty()){
            int w = -q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            answer = max(answer, w);
            
            if(x == n - 1 && y == m-1) break;
            
            
            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(check[nx][ny]) continue;
                check[nx][ny] = true;
                q.push({-grid[nx][ny], {nx,ny}});
            }
            
        }
        return answer;
    }
};
