/**
 * problem : https://leetcode.com/problems/first-bad-version/
 * algorithm : binary search
 * time complexity : O(logN)
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        long right = n;
        while(left < right) {
            int m = (left + right) / 2;
            if(isBadVersion(m)) right = m;
            else left = m + 1;
        }
        return left;
    }
};
