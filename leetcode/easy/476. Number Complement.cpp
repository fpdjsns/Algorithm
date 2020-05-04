/**
 * problem : https://leetcode.com/problems/number-complement/
 * time complexity : O(logN)
 */

class Solution {
public:
    int findComplement(int num) {
        long long int tmp = 1;
        while(tmp <= num) {
            tmp *= 2;
        }
        return tmp -1 - num;
    }
};
