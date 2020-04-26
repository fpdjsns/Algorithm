/**
 * problem : https://leetcode.com/problems/longest-common-subsequence/
 * algorithm : DP
 * time complexity : O(NM)
 */
 
class Solution {
    vector<vector<int>> dp;
    string s1, s2;
    int n, m;
    int dfs(int ind1, int ind2) {
        if(ind1 >= n || ind2 >= m) return 0;
        int& ret = dp[ind1][ind2];
        if(ret != -1) return ret;
        ret = 0;
        
        if(s1[ind1] == s2[ind2]) ret = 1 + dfs(ind1+1, ind2+1);
        else ret = max(dfs(ind1, ind2+1), dfs(ind1+1, ind2));
        
        return ret;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        s1=  text1; s2 = text2;
        n = text1.size(); m = text2.size();
        int ans = 0;
        dp = vector<vector<int>>(text1.size(), vector<int>(text2.size(), -1));
        return dfs(0, 0);
    }
};
