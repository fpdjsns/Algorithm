/**
 * problem : https://leetcode.com/problems/basic-calculator/
 * time complexity : O(N)
 */

class Solution {
        
public:
    int calculate(string s) {
        stack<int> st;
        bool sign = true;
        int num = 0;
        int tmpNum = 0;
        
        for(auto c : s) {
            if(c == ' ') continue;
            
            if(c >= '0' && c <= '9') {
                tmpNum *= 10;
                tmpNum += (c - '0');
            } else {
                num += (sign ? tmpNum : -1 * tmpNum);
                tmpNum = 0;
                if (c == '(') {
                    st.push(num);
                    st.push(sign);
                    num = 0;
                    sign = true;
                } else if(c == ')') {
                    num *= st.top() ? 1 : -1; st.pop(); // sign
                    num += st.top(); st.pop(); // num
                    sign = true;
                } else if(c == '+' || c == '-') {
                    sign = (c == '+');
                }
            }
        }
        num += sign ? tmpNum : -1 * tmpNum;
        
        return num;
    }
};
