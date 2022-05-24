/**
 * problem : https://leetcode.com/problems/longest-valid-parentheses/
 * time complexity : O(N)
 * algorithm : DP, STACK
 */
 
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<int> dp(s.size(), 0);
        int answer = 0;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(c == '(') {
                st.push(i);
            } else {
                if(st.empty()) continue;
                int index = st.top();
                st.pop();
                dp[i] = i - index + 1;
                if(index > 0) dp[i] += dp[index-1];
            }
            answer = max(answer, dp[i]);
        }
        return answer;
    }
};
