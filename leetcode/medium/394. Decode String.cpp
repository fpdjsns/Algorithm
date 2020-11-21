/**
 * problem : https://leetcode.com/problems/decode-string/
 * time complexity : O(N). N = |s|
 * data structure : stack
 */

class Solution {
public:
    string decodeString(string s) {
        stack<pair<int,string>> st;
        st.push({1, ""});
        
        int cnt = 0;
        string answer;
        for(int i=0;i<s.size();i++){
            char now = s[i];
            if (now >= '0' && now <= '9') cnt = 10*cnt + now - '0';
            else if (now == '[') { st.push({cnt, ""}); cnt = 0; }
            else if (now == ']') {
                string splicing;
                for(int j=0;j<st.top().first;j++){
                    splicing += st.top().second;
                }
                st.pop();
                st.top().second += splicing;
                
            } else { // alphabet
                st.top().second += now;
            }
        }
        return st.top().second;
    }
};
