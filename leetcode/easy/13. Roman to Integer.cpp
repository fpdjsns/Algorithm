/**
 * problem : https://leetcode.com/problems/roman-to-integer/
 * time complexity : O(2N) // N = |s|
 */
 
class Solution {
    map<char, int> romanInt = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    
public:
    int romanToInt(string s) {
        stack<int> st;
        for(auto c: s) {
            int value = romanInt[c];
            if(value > 1) {
                if(!st.empty() && 
                   (st.top() == value / 5 || st.top() == value / 10)){
                    value -= st.top();
                    st.pop();
                }
            }
            st.push(value);
        }
        
        int answer = 0;
        while(!st.empty()){
            answer += st.top();
            st.pop();
        }
        return answer;
    }
};
