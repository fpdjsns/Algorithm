/*
 * problem : https://leetcode.com/problems/valid-perfect-square/
 * algorithm : binary search
 * time complexity : O(logN)
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        while(l <= r) {
            long long int m = ((long long int)l + r)/2;
            if(m*m == num) return true;
            if(m*m < num) l = m+1;
            else r = m-1;
        }
        return false;
    }
};
