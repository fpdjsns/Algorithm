/** 
 * problem : https://leetcode.com/problems/removing-stars-from-a-string/description/
 * time complexity : O(N)
 * data structure : stack
 */
 
class Solution {
public:
    string removeStars(string s) {
        stack<int> st;
        for(auto c: s) {
            if(c == '*') st.pop();
            else st.push(c);
        }
        int n = st.size();
        string answer(n, ' ');
        while(!st.empty()) {
            answer[--n] = st.top();
            st.pop();
        }
        return answer;
    }
};
