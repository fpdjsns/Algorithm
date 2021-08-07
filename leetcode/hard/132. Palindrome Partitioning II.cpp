/**
 * problem : https://leetcode.com/problems/palindrome-partitioning-ii/
 * time complexity : O(N^2)
 * algorithm : DP
 */

class Solution {
public:
    int minCut(string str) {
        int n = str.size();
        vector<vector<bool>> isPelin(n, vector<bool>(n, false));
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                isPelin[i][j] = true;
        
        for(int s=n-1; s>=0; s--){
            for(int e=s+1; e<n; e++){
                isPelin[s][e] = (str[s] == str[e]);
                if(s < e-1) isPelin[s][e] = isPelin[s][e] & isPelin[s+1][e-1];
            }
        }
        
        // s[~i] 문자열을 펠린드롭화 하기 위한 최저 커팅 횟수
        vector<int> dp = vector<int>(n, n);
        for(int e=0; e<n; e++){
            int& ret = dp[e];
            if(isPelin[0][e]) {
                ret = 0;
                continue;
            }
            
            for(int s=1; s<=e; s++){
                if(!isPelin[s][e]) continue;
                // str[s: e] is palindrome 
                ret = min(ret, 1 + dp[s-1]);
            }
        }
        
        return dp[n-1];
    }
};
