/**
 * problem : https://leetcode.com/problems/divide-two-integers/
 * time complexity : O(log(dividend))
 */
 
class Solution {
public:
    int divide(int dividend, int divisor) {
        long answer = 0;
        bool sign = (dividend >= 0 && divisor >= 0) || (dividend <0 && divisor <0);
        
        long a = labs(dividend);
        long b = labs(divisor);
        
        if(b == 1) {
            if(sign) return min((long)INT_MAX, a);
            else return max((long)INT_MIN, -a);
        }
        
        while(a >= b) {
            long tmp = b;
            long cnt = 1;
            while(a >= tmp + tmp) {
                cnt += cnt;
                tmp += tmp;
            }
            a -= tmp;
            answer += cnt;
        }
        if(!sign) answer *= -1;
        return answer;
    }
};
