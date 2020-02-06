/*
 * 문제 : https://leetcode.com/problems/as-far-from-land-as-possible/
 * 시간복잡도 : O(NM) // N : grid 전체 크기, M : land의 개수
 *  : BFS
 */

class Solution {
private: 
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int size = grid.size();
        
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(grid[i][j] == 0) continue;
                
                // land인 경우 q에 push
                q.push({i, j});
                grid[i][j] = -1;
            }
        }
        
        while(!q.empty()) {
                    
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            int dis = grid[x][y] == -1 ? 0 : grid[x][y];
            dis++;
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || nx >= size || ny < 0 || ny >= size) continue; // grid 범위 넘어가는 경우
                if(grid[nx][ny] == -1) continue; // land인 경우
                if(grid[nx][ny] != 0 && grid[nx][ny] <= dis) continue; // 이미 세팅된 다른 land로부터의 거리보다 더 먼 경우
                
                grid[nx][ny] = dis;
                q.push({nx, ny});
            }
        }
        
        int maxDis = -1;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                maxDis = max(maxDis, grid[i][j]);
            }
        }
        
        return maxDis == 0 ? -1 : maxDis;
    }
};
