/**
 * problem : https://leetcode.com/problems/uncrossed-lines/
 * algorithm : DP
 * time complexity : O(NM)
 */
 
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int ans = 0;
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                int& ret = dp[i+1][j+1];
                if(A[i] == B[j]) ret = dp[i][j] + 1;
                else ret = max(dp[i][j+1], dp[i+1][j]);
                ans = max(ans, ret);
            }
        }
        return ans;
    }
};
