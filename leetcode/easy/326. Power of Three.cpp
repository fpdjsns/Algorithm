/**
 * problem : https://leetcode.com/problems/power-of-three/
 * time complexity : log(n)
 */
 
class Solution {
public:
    bool isPowerOfThree(int n) {
        unsigned num = n;
        if(num == 0) return false;
        while(num > 1) {
            if(num % 3 != 0) return false;
            num /= 3;
        }
        return true;
    }
};
