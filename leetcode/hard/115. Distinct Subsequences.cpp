/**
 * problem : https://leetcode.com/problems/distinct-subsequences/
 * time complexity : O(NM) N = |s|, M = |t|
 * algorithm : DP
 */

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long long> dp(t.size() + 1);
        dp[0] = 1;
        for(int i=0; i<s.size(); i++) {
            for(int j=t.size()-1; j>=0; j--){
                if(s[i] != t[j]) continue;
                dp[j+1] = (dp[j+1] + dp[j]) % 2147483647L;
            }
        }
        return dp[t.size()];
    }
};
