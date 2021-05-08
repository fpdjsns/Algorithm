/**
 * problem : https://leetcode.com/problems/delete-operation-for-two-strings/
 * time complexity : O(NM) // N = |word1|, M = |word2|
 * algorithm : LCS (Longest Common Subsequence)
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(); int m = word2.size(); 
        
        vector<vector<int>> dp(n+1, vector<int>(m + 1));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]) 
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }    
        }
        return n + m - 2 * dp[n][m];
    }
};
