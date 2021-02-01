/**
 * problem : https://leetcode.com/problems/number-of-1-bits/
 * time complexity : O(logN)
 */
 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n > 0) {
            n &= (n-1);
            cnt++;
        }
        return cnt;
        
    }
};
