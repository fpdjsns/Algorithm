/**
 * problem : https://leetcode.com/problems/nth-magical-number/
 * time complexity : O(logN)
 * algorithm : binary search
 */

class Solution {
    int mod = 1e9 + 7;
    
    int gcd(int a, int b) {
        if (b == 0) 
            return a;
        else
            return gcd(b, a%b);
    }

    int getLcm(int a, int b) {
        int tmp = gcd(a, b);
        return a*b / tmp;
    }

public:
    int nthMagicalNumber(int n, int a, int b) {
        int lcm = getLcm(a,b);
        long l=min(a,b); 
        long r=1L*n*max(a,b);
        int answer = 0;
        
        while(l<=r) {
            long m = l + (r - l) / 2;
            long cnt = m/a + m/b - m/lcm;
            
            if(cnt == n)
                answer = m % mod;
            
            if(cnt >= n)
                r = m - 1;
            else 
                l = m + 1;
        }
        
        return answer;
    }
};
