/**
 * problem : https://leetcode.com/problems/arranging-coins/
 * algorithm : parametric search
 * time complexity : O(logN)
 */
 
class Solution {
public:
    int arrangeCoins(int n) {
        if(n <= 1) return n;
        int l = 0;
        int r = n;
        
        int ans = 0;
        while(l <= r) {
            int m = (l + r) / 2;
            long long sum = (long long)m * (m + 1) / 2;
            if(sum <= n) {
                ans = m;
                l = m + 1;
            }
            else r = m-1;
        }
        return ans;
    }
};
