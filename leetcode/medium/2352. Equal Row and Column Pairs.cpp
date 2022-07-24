/**
 * problem : https://leetcode.com/problems/equal-row-and-column-pairs/
 * time complexity :  O(N^3)
 */
 
 class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int answer = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                bool canAns = true;
                for(int k=0; k<n; k++){
                    if(grid[i][k] == grid[k][j]) continue;
                    canAns = false;
                    break;
                }
                answer += canAns;
            }
        }
        
        return answer;
    }
};
