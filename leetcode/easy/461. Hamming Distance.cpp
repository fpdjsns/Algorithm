/**
 * problem : https://leetcode.com/problems/hamming-distance/
 * time complexity : O(N)
 */
 
class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x ^ y;
        int answer = 0;
        while(x > 0) {
            answer += x%2;
            x = x >> 1;
        }
        return answer;
    }
};
