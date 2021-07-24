/**
 * problem : https://leetcode.com/problems/maximal-rectangle/
 * time complexity : O(N^3)
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int row = matrix.size(); 
        int col = matrix[0].size();
        
        vector<int> height(col, 0);
        int answer = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == '0') {
                    height[j] = 0;
                }
                else {
                    height[j]++;
                }
                int minHeight = height[j];
                for(int k=j; k >= 0; k--){
                    minHeight = min(minHeight, height[k]);
                    if(minHeight == 0) break;
                    answer = max(answer, (j-k+1) * minHeight);
                }
            }
        }
        return answer;
    }
};
