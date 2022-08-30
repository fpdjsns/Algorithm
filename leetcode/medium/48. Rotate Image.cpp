/**
 * problem : https://leetcode.com/problems/rotate-image/
 * time complexity : O(N^2)
 * space complexity : O(1)
 */
 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<(n+1)/2; i++){ 
            for(int j=i; j<n-1-i; j++){
                int tmp = matrix[i][j];
                
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-i-1];
                matrix[j][n-i-1] = tmp;
            }
        }
    }
};
