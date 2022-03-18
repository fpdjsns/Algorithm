/**
 * problem : https://leetcode.com/problems/remove-duplicate-letters/
 * time complexity : O(N)
 */

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        
        vector<int> cnts(26, 0);
        for(auto ch: s) cnts[ch-'a']++;
        
        vector<bool> check(26, false);
        stack<int> st;
        for(int i=0; i<n; i++){
            int now = s[i]-'a';
            cnts[now]--;
            if(check[now]) continue;
            while(!st.empty() && now < st.top() && cnts[st.top()] > 0) {
                check[st.top()] = false;
                st.pop(); 
            }
            st.push(now);
            check[now] = true;
        }
        
        string answer = "";
        while(!st.empty()) {
            answer += (st.top() + 'a');
            st.pop();
        }
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};
