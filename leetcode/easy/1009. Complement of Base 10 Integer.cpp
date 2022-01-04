/**
 * problem : https://leetcode.com/problems/complement-of-base-10-integer/
 * time complexity : O(1)
 */

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int len = log2(n) + 1;
        return (1 << len) - n - 1;
    }
};
