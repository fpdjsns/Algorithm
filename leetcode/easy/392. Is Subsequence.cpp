/**
 * problem : https://leetcode.com/problems/is-subsequence/
 * time complexity : DP
 * algorithm : O(NM)
 */
 
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == t) return true;
        if(s == "") return true;
        if(t == "") return false;
        
        vector<vector<bool>> dp(s.size()+1, vector<bool>(t.size(), false));
        for(int j=0;j<=t.size();j++)
            dp[0][j] = true;
        
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                dp[i][j] = (dp[i][j-1] | (dp[i-1][j-1] && t[j-1] == s[i-1]));
            }
        }
        return dp[s.size()][t.size()];
    }
};
