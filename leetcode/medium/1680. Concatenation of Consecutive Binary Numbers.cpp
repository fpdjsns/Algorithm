/**
 * problem : https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
 * time complexity : O(N)
 */
 
class Solution {
    const int MOD = 1e9 + 7;
public:
    int concatenatedBinary(int n) {
        long long int sum = 0;
        for(int i=1; i<=n; i++) 
            sum = ((sum << ((int)log2(i) + 1)) + i) % MOD;
        return sum;
    }
};
