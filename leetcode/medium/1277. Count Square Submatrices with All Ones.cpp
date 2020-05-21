/**
 * problem : https://leetcode.com/problems/count-square-submatrices-with-all-ones/
 * algorithm : DP. subsum
 * time complexity : O(NMK) // N = |matrix|, M = |matrix[0]|, K = min(N, M)
 */
 
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> columnSum(r+1, vector<int>(c+1));
        vector<vector<int>> rowSum(r+1, vector<int>(c+1));
        for(int i=0; i<r; i++){
            for(int j=0;j<c;j++){
                columnSum[i+1][j+1] = columnSum[i+1][j] + matrix[i][j];
                rowSum[i+1][j+1] = rowSum[i][j+1] + matrix[i][j];
            }
        }
        
        int ans = 0;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                for(int size=1;;size++){
                    if(j+size-1 > c || i+size-1 > r) break;
                    if(size == rowSum[i+size-1][j+size-1] - rowSum[i-1][j+size-1]
                      && size == columnSum[i+size-1][j+size-1] - columnSum[i+size-1][j-1]){
                        ans++;
                    }
                    else break;
                }
            }
        }
        
        return ans;
    }
};
