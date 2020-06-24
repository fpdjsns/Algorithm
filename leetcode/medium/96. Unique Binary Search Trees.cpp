/**
 * problem : https://leetcode.com/problems/unique-binary-search-trees/
 * time complexity : O(N)
 * algorithm : DP
 */
 
class Solution {
    vector<int> memoization;
    
    // dp[n] = sum(dp[i-1] * dp[n-i]) (1 <= i <= n)
    int solve(int n) {
        if(n <= 1) return 1;
        
        int& ret = memoization[n];
        if(ret != -1) return ret;
        ret = 0;
        
        for(int first = 1; first<=n; first++){
            int left = solve(first-1);
            int right = solve(n-first);
            ret += left * right;
        }
        return ret;
    }
public:
    int numTrees(int n) {
        memoization = vector<int>(n + 1, -1);
        return solve(n);
    }
};
