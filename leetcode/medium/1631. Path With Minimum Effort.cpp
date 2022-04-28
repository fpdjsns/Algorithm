/**
 * problem : https://leetcode.com/problems/path-with-minimum-effort/
 * time complexity : O(row x col x logN) N = max(heights[i][j])
 * algorithm : Binary Search
 */
 
class Solution {
    int row, col;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    bool isValid(vector<vector<int>>& heights, int maxDiff){
        vector<vector<bool>> check(row, vector<bool>(col, false));
        
        queue<pair<int,int>> q;
        q.push({0,0});
        check[0][0];
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                if(abs(heights[x][y] - heights[nx][ny]) > maxDiff) continue;
                if(check[nx][ny]) continue;
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        return check[row-1][col-1];
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();
        
        int left = 0;
        int right = 1e6;
        int m = 0;
        int answer = 0;
        while(left <= right) {
            m = (left + right) / 2;
            if(isValid(heights, m)) {
                answer = m;
                right = m-1;
            }else{
                left = m+1;
            }
        }
        
        return answer;
    }
};
