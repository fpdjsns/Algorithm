/**
 * problem : https://leetcode.com/problems/making-a-large-island/
 * time/space complexity : O(NM)
 * algorithm : DFS
 */

class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int n, m;
    int dfs(int num, int x, int y, vector<vector<int>>& array){
        queue<pair<int,int>> q; 
        q.push({x, y});
        int size = 0;
        while(!q.empty()) {
            int x= q.front().first;
            int y = q.front().second;
            q.pop();
            if(array[x][y] != 1) continue;
            array[x][y] = num;
            size++;
            for(int k=0;k<4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(array[nx][ny] != 1) continue;
                q.push({nx, ny});
            }
        }
        return size;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        vector<vector<int>> array = grid;
        
        int num = 2;
        int answer = 0;
        unordered_map<int, int> landSize;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(array[i][j] != 1) continue;
                int size = dfs(num, i, j, array);
                landSize[num] = size;
                answer = max(answer, size);
                num++;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(array[i][j] != 0) continue;
                set<int> lands;
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    lands.insert(array[nx][ny]);
                }
                
                int sum = 1;
                for(auto land:lands){
                    sum += landSize[land];
                }
                answer = max(answer, sum);
            }
        }
        
        return answer;
    }
};
