/**
 * problem : https://leetcode.com/problems/maximal-square/
 * algorithm : DFS
 */
 
class Solution {
public:
    int dfs(int x, int y, vector<vector<char>>& matrix) {
        int ans = 1e9;

        int i, j;
        for(i=x; i < min((int)matrix.size(), x+ans); i++){
            if(matrix[i][y] == '0') break;
            int size = 0;
            for(j=y; j<matrix[i].size(); j++){
                if(matrix[i][j] == '0') break;
                size++;
            }
            ans = min(size, ans);
        }
        ans = min(i-x, ans);
        return ans * ans;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] == '0') continue;
                ans = max(ans, dfs(i,j,matrix));
            }
        }
        return min((int)matrix.size() * (int)matrix.size(), ans);
    }
};
