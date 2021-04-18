/**
 * problem : https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
 * time complexity : O(N^2 * M^2)
 * algorithm : subSum, dp
 */
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> subSum(n+1, vector<int>(m+1));
        
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=0; j<m; j++){
                sum += matrix[i][j];
                subSum[i+1][j+1] = subSum[i][j+1] + sum;
            }
        }
        
        int answer = 0;
        for(int x1=0; x1 < n; x1++){
            for(int x2=x1+1; x2<=n;x2++){
                for(int y1=0; y1 < m; y1++){
                    for(int y2=y1+1; y2<=m; y2++){
                        // (x1, x2] (y1, y2]
                        if(subSum[x2][y2] - subSum[x1][y2] - subSum[x2][y1] + subSum[x1][y1] == target)
                            answer++;
                    }
                }
            }
        }
        return answer;
    }
};
