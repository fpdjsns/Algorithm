/**
 * problem : https://leetcode.com/problems/island-perimeter/
 * time complexity : O(NM)
 */
 
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 0) continue;
                ans += 4;
                if(i-1 >= 0) ans -= grid[i-1][j];
                if(j-1 >= 0) ans -= grid[i][j-1];
                if(i+1 < grid.size()) ans -= grid[i+1][j];
                if(j+1 < grid[i].size()) ans -= grid[i][j+1];
            }
        }
        return ans;
    }
};
