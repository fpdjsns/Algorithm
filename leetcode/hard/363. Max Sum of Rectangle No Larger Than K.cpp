/**
 * problem : https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
 * time complexity : O(N^2 * M^2)
 * algorithm : subsum
 */
 
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int subsum[m+1][n+1];
        memset(subsum, 0, sizeof(subsum));
        
        for(int i=1; i<=m; i++){
            int sum = 0;
            for(int j=1; j<=n; j++){
                sum += matrix[i-1][j-1];
                subsum[i][j] = subsum[i-1][j] + sum;
            }
        }
        
        int answer = -1e9;
        for(int x1=0; x1<m; x1++){
            for(int y1=0; y1<n; y1++){
                for(int x2=x1+1; x2<=m; x2++){
                    for(int y2=y1+1; y2<=n; y2++){
                        int sum = subsum[x2][y2] - subsum[x1][y2] - subsum[x2][y1] + subsum[x1][y1];
                        if(sum > k) continue;
                        answer = max(answer, sum);
                    }
                }
            }
        }
        return answer;
    }
};
