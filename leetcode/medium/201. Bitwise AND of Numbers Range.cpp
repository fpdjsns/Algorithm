/**
 * problem : https://leetcode.com/problems/bitwise-and-of-numbers-range/
 * time complexity : O(logN). N = min(m, n).
 */

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int cnt = 0;
        while(m < n) {
            m = m >> 1;
            n = n >> 1;
            cnt++;
        }
        return n<<cnt;
    }
};
