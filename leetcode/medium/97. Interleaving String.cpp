/**
 * problem : https://leetcode.com/problems/interleaving-string/
 * time/spce complexity : O(NM)
 * algorithm : DP(memoization)
 */
 
class Solution {
    vector<vector<int>> dp;
    bool canAns(int a, int b, int c, const string& s1, const string& s2, const string& s3) {
        if(a >= s1.size() && b >= s2.size()) // must end
            return c >= s3.size();
        
        if(dp[a][b] != -1) return dp[a][b];
        if(a < s1.size() && s1[a] == s3[c] && canAns(a+1, b, c+1, s1, s2, s3)) return dp[a][b] = true;
        if(b < s2.size() && s2[b] == s3[c] && canAns(a, b+1, c+1, s1, s2, s3)) return dp[a][b] = true;
        return dp[a][b] = false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return canAns(0, 0, 0, s1, s2, s3);
    }
};
