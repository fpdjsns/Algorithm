/**
 * problem : https://leetcode.com/problems/palindromic-substrings/
 * time complexity : O(N^2)
 * algorithm : DP
 */
 
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n+1, false));
        int answer = 0;
        for(int size = 1; size <= n; size++){
            for(int start = 0; start <= n - size; start++){
                int end = start + size - 1;
                dp[start][end] = (s[start] == s[end]) && (start+1 <= end-1 ? (dp[start+1][end-1]) : true);
                answer += dp[start][end];
            }
        }
        return answer;
    }
};
