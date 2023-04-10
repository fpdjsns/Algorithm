/**
 * problem : https://leetcode.com/problems/valid-parentheses/description/
 * time complexity : O(N)
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c : s) {
            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if(st.empty()) return false;
                int prev = st.top();
                st.pop();
                if((c == ')' && prev == '(') || 
                (c == '}' && prev == '{') || 
                (c == ']' && prev == '[')) continue;
                return false;
            }
        }
        return st.empty();
    }
};
