/**
 * problem : https://leetcode.com/problems/unique-paths-ii/
 * algorithm : DP
 * time complexity : O(NM)
 */
 
class Solution {
public:
    vector<vector<int>> d = vector<vector<int>>();
    vector<vector<int>> obstacle = vector<vector<int>>();
    int row = 0;
    int col = 0;
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};
    
    int go(int x, int y){
        int& ret = d[x][y];
        if(ret != -1)
            return ret;
        ret = 0;
        
        if(obstacle[x][y] == 1)
            return ret = 0;
        if(x==row-1 && y==col-1)
            return ret = 1;
        
        for(int i=0; i<2; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < row && ny < col)
                ret += go(nx, ny);
        }
        
        return ret;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        obstacle = obstacleGrid;
        row = obstacleGrid.size();
        col = obstacleGrid[0].size();
        d.resize(row, vector<int>(col, -1));
        return go(0, 0);
    }
};
