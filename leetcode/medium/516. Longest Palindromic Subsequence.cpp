/**
 * problem : https://leetcode.com/problems/longest-palindromic-subsequence/description/
 * time complexity : O(N^2)
 * space complexity : O(N^2)
 * algorithm : dp
 */

class Solution {

    int getAns(string& s, vector<vector<int>>& dp, int x, int y) {
        if(x > y) return 0;

        int& ret = dp[x][y];
        if(ret != 1e9) return ret;
        if(x == y) return ret = 1;
        ret = 0;

        if(s[x] == s[y])
            ret = max(ret, getAns(s, dp, x+1, y-1) + 2);
        else
            ret = max(ret, max(getAns(s, dp, x+1, y), getAns(s, dp, x, y-1)));

        return ret;
    }

public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9)); // dp[i][j] = s[i~j] answer
        return getAns(s, dp, 0, n-1);
    }
};
