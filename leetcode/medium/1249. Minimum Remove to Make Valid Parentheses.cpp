/**
 * problem : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
 * time complexity : O(N)
 * data structure : stack
 */
 
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string answer = "";
        stack<int> st;
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            if(ch == '(')  
                st.push(answer.size());
            else if(ch == ')'){
                if(st.empty()){
                    continue;
                } else {
                    st.pop();
                }
            } 
            answer += ch;
        }
        
        while(!st.empty()) {
            answer.erase(st.top(), 1);
            st.pop();
        }
        
        return answer;
    }
};
