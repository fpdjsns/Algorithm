/**
 * problem : https://leetcode.com/problems/ones-and-zeroes/
 * time complexity : O(|str|MN)
 * algorithm : DP
 */

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(auto str: strs) {
            pair<int, int> cnts;
            for(auto c: str) {
                cnts.first += (c == '0');
                cnts.second += (c == '1');
            }
            for(int i=m - cnts.first; i >= 0; i--){
                int nx = i + cnts.first;
                for(int j=n - cnts.second; j >= 0; j--){
                    int ny = j + cnts.second;
                    dp[nx][ny] = max(dp[nx][ny], dp[i][j] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};
